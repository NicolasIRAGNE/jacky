cmake_minimum_required(VERSION 3.20)

project(libjacky VERSION 0.0.1)

add_library(libjacky)

target_compile_definitions(libjacky PUBLIC cxx_std_20)
set_target_properties(libjacky PROPERTIES CXX_EXTENSIONS ON)

target_sources(libjacky
    PRIVATE
        cpu.cpp
    PUBLIC
        register.h
        cpu.h
)

target_include_directories(libjacky PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(libjacky PUBLIC
    spdlog::spdlog
)

add_subdirectory(cpus)

install(TARGETS libjacky
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)