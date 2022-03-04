cmake_minimum_required(VERSION 3.19)
project(Project_PJAText2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_PJAText2 main.cpp file_flag.h file_flag.cpp input_flag.h input_flag.cpp help_flag.h help_flag.cpp
        newline_flag.h newline_flag.cpp output_flag.cpp output_flag.h digit_file.cpp digit_flag.h numbers_flag.cpp numbers_flag.h
        chars_flag.cpp chars_flag.h words_flag.cpp words_flag.h sort_flag.h sort_flag.cpp revsort_flag.cpp revsort_flag.h
        bylength_flag.cpp bylength_flag.h anagrams_flag.cpp anagrams_flag.h palindromes_flag.cpp palindromes_flag.h digits_sum_flag.cpp
        digits_sum_flag.h)