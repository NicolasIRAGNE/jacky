cmake_minimum_required(VERSION 3.20)

project(jacky-exec VERSION 0.0.1)

add_executable(jacky-exec)

target_sources(jacky-exec PRIVATE main.cpp)
target_link_libraries(jacky-exec libjacky)

install(TARGETS jacky-exec DESTINATION bin)