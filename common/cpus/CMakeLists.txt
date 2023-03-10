option(JACKY_ENABLE_CPU_V1 "Enable V1 CPU support" ON)

if (JACKY_ENABLE_CPU_V1)
    add_subdirectory(v1)
    target_compile_definitions(libjacky PUBLIC -DJACKY_ENABLE_CPU_V1)
    target_link_libraries(libjacky PUBLIC jacky::v1_cpu)
endif(JACKY_ENABLE_CPU_V1)
