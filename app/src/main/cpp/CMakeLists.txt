cmake_minimum_required(VERSION 3.10.2)

project("leveldbsample")

if ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "i686")
    set(lib-abi x86)
elseif ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
    set(lib-abi x86_64)
elseif ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "armv7-a")
    set(lib-abi armeabi-v7a)
elseif ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "aarch64")
    set(lib-abi arm64-v8a)
endif()

set(leveldb-lib ${CMAKE_SOURCE_DIR}/libs/leveldb/${lib-abi}/libleveldb.a)

include_directories( ${CMAKE_SOURCE_DIR}/include )

add_library(leveldbsample
        SHARED
        native-lib.cpp)

find_library(
        log-lib
        log)

target_link_libraries(
        leveldbsample
        ${leveldb-lib}
        ${log-lib})