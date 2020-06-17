cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(testApplication)

add_subdirectory(lib)
set(SOURCES main.cpp)
set(HEADERS include)

add_executable(testapp ${SOURCES})
target_link_libraries(testapp xstring)
target_include_directories(testapp PUBLIC ${HEADERS})
