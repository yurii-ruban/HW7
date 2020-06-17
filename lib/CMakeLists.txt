cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(xString)

set(SOURCES src/xstring.cpp)
set(HEADERS include)

add_library(xstring SHARED ${SOURCES})
target_include_directories(xstring PUBLIC ${HEADERS})
