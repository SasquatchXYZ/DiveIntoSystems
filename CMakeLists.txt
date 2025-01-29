cmake_minimum_required(VERSION 3.30)
project(DiveIntoSystems C)

set(CMAKE_C_STANDARD 23)

add_executable(DiveIntoSystems main.c)

add_executable(Functions Chapter1/functions.c)
add_executable(TestArray Chapter1/test_array.c)
add_executable(StringExamples Chapter1/string_examples.c)
add_executable(StructDemo Chapter1/struct_demo.c)
add_executable(LValuesDemo Chapter1/lvalues_demo.c)
add_executable(StructsToFunctions Chapter1/passing_structs_to_functions.c)

add_executable(LocalAndGlobalVariables Chapter2/local_and_global_variables.c)
