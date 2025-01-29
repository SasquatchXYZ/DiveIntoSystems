cmake_minimum_required(VERSION 3.30)
project(DiveIntoSystems C)

set(CMAKE_C_STANDARD 23)

add_executable(DiveIntoSystems main.c)
add_executable(Functions functions.c)
add_executable(TestArray test_array.c)
add_executable(StringExamples string_examples.c)
add_executable(StructDemo struct_demo.c)
add_executable(LValuesDemo lvalues_demo.c)
add_executable(StructsToFunctions passing_structs_to_functions.c)
