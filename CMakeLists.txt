cmake_minimum_required(VERSION 3.26)
project(gmp_testing C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_COMPILER "gcc")
#find_package(GMP REQUIRED)
#add_compile_options(-lgmp) # -O3 -march=native)

add_executable(gmp_testing main.c)
target_link_libraries(gmp_testing gmp libgmp)