cmake_minimum_required(VERSION 3.7)

project(zlib-test)

#set (CMAKE_CXX_FLAGS "-O3")
set (CMAKE_CXX_FLAGS "-g")

include_directories(/mnt/store/current/src/boost_1_67_0 /mnt/store/current/src/boost_1_67_0/boost)

set(CMAKE_CXX_STANDARD 14)

link_directories(/usr/local/lib)

add_executable(unzip-noheader unzip-noheader.cpp base64-string.h)

target_link_libraries(unzip-noheader boost_system boost_iostreams stdc++ z pthread)
