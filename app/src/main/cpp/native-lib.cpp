#include <jni.h>
#include <string>

#include <cassert>
#include <android/log.h>
#include <leveldb/db.h>

#define APPNAME "LevelDBSample"

std::string jstring2string(JNIEnv *env, jstring jStr) {
    if (!jStr)
        return "";

    const char *nativeString = env->GetStringUTFChars(jStr, nullptr);

    std::string ret = nativeString;
    env->ReleaseStringUTFChars(jStr, nativeString);

    return ret;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_fornity_leveldbsample_MainActivity_getLaunchCount(
        JNIEnv* env,
        jobject, jstring jFilesPath) {
    std::string dbPath = jstring2string(env, jFilesPath) + "/testdb";
    std::string value;
    std::string key = "counter";

    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, dbPath, &db);

    if (status.ok()) {
        __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "DB path: %s", dbPath.c_str());

        int counter = 0;

        status = db->Get(leveldb::ReadOptions(), key, &value);

        if (status.ok()) {
            counter = atoi(value.c_str());
        }

        counter++;
        value = std::to_string(counter);
        status = db->Put(leveldb::WriteOptions(), key, value);

        if (status.ok()) {
            __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "Counter value: %s", value.c_str());
        }

        delete db;
    }

    return env->NewStringUTF(value.c_str());
}