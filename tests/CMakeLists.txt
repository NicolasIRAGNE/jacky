cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

include(GoogleTest)
include (CTest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(jacky-tests)

target_sources(jacky-tests
  PRIVATE
    cpu_tests.cpp
    registers_tests.cpp
)

target_link_libraries(
    jacky-tests
    libjacky
    gtest_main
)

gtest_discover_tests(jacky-tests)