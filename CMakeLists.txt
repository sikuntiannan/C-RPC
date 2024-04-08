cmake_minimum_required (VERSION 3.22)

project ("ALL")

set(CMAKE_DEBUG_POSTFIX "_d")

set(CMAKE_INSTALL_PREFIX ./install/)

set(CMAKE_CXX_STANDARD 20)

IF (CMAKE_BUILD_TYPE STREQUAL Debug)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Og -g")
ELSEIF (CMAKE_BUILD_TYPE STREQUAL Release)
    #-s 可执行文件中删除所有符号表和重新定位信息
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Ofast -s")
ELSE ()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -O0 -s")
ENDIF()

add_subdirectory("ThreadSafeDataStruct")