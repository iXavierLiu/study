cmake_minimum_required(VERSION 3.18.2)
project(leetcode)

aux_source_directory(test DIR_TEST)

aux_source_directory(0001_tow_sum DIR_SRC_0001)
add_executable(0001_tow_sum ${DIR_TEST} ${DIR_SRC_0001})
aux_source_directory(0002_add_two_numbers DIR_SRC_0002)
add_executable(0002_add_two_numbers ${DIR_TEST} ${DIR_SRC_0002})