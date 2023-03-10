cmake_minimum_required(VERSION 3.20)

project(jacky-exec VERSION 0.0.1)

add_executable(jacky-exec)

target_compile_features(jacky-exec PUBLIC cxx_std_20)

target_sources(jacky-exec
    PRIVATE
        main.cpp
        exec.h
)
target_link_libraries(jacky-exec PUBLIC libjacky)

install(TARGETS jacky-exec DESTINATION bin)