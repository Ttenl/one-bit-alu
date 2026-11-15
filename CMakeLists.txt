cmake_minimum_required(VERSION 3.16)
project(one_bit_alu LANGUAGES CXX)

add_executable(one_bit_alu main.cpp)
target_compile_features(one_bit_alu PRIVATE cxx_std_17)
set_target_properties(one_bit_alu PROPERTIES CXX_EXTENSIONS OFF)
