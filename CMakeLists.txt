cmake_minimum_required(VERSION 3.26)
project(gmp_testing C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_COMPILER "clang")
add_compile_options(-O3 -march=native -Wall -Wextra -Wpedantic)

add_executable(gmp_testing
        main.c)


# Find the GMP library
find_library(GMP_LIBRARY gmp)

# Check if GMP library is found
if(GMP_LIBRARY)
    # Link against the GMP library
    target_link_libraries(gmp_testing PRIVATE ${GMP_LIBRARY})
else()
    message(FATAL_ERROR "GMP library not found")
endif()