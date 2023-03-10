cmake_minimum_required(VERSION 3.20)

project(jacky VERSION 0.0.1)

option(JACKY_BUILD_ASM "Build jacky-asm" OFF)
option(JACKY_BUILD_EXEC "Build jacky-exec" ON)
option(JACKY_BUILD_TESTS "Build unit tests" ON)

add_subdirectory(common)
add_subdirectory(3rdparty)

if (JACKY_BUILD_ASM)
    add_subdirectory(asm)
endif()

if (JACKY_BUILD_EXEC)
    add_subdirectory(exec)
endif()

if (JACKY_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()