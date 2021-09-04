# leveldb-ndk-android-sample

LevelDB source: https://github.com/google/leveldb/releases/tag/1.23
Static libraries were compiled using the following command for each architecture:
```
cmake -DCMAKE_TOOLCHAIN_FILE=/path/to/ndk/build/cmake/android.toolchain.cmake -DANDROID_NATIVE_API_LEVEL=21 -DCMAKE_SYSTEM_NAME=Android-DCMAKE_SYSTEM_VERSION=21 -DANDROID_PLATFORM=android-21 -DANDROID_NDK=/path/to/ndk/21.4.7075529 -DCMAKE_MAKE_PROGRAM=/path/to/cmake/3.10.2.4988404/bin/ninja.exe -DCMAKE_CXX_FLAGS=-std=c++14 -DCMAKE_BUILD_TYPE=Release -GNinja -DANDROID_ABI={ABI} ./ && cmake --build ./
```