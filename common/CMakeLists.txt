cmake_minimum_required(VERSION 3.20)

project(libjacky VERSION 0.0.1)

add_library(libjacky STATIC)

set_target_properties(libjacky PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_sources(libjacky
    PRIVATE
        logger.cpp
        cpu.cpp
    PUBLIC
        logger.h
        register.h
        cpu.h
)

target_include_directories(libjacky PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS libjacky
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)