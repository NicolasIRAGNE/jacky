add_library(v1_cpu)
add_library(jacky::v1_cpu ALIAS v1_cpu)

target_sources(v1_cpu
    PRIVATE
        v1.h
        v1.cpp
)

target_include_directories(v1_cpu
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(v1_cpu
    PUBLIC
        libjacky
)

target_link_libraries(libjacky
    PUBLIC
        jacky::v1_cpu
)