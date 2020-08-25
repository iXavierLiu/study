cmake_minimum_required(VERSION 3.18.2)
project(sort)

include_directories(src)
aux_source_directory(src DIR_SRC)
aux_source_directory(test DIR_TEST)
add_executable(sort ${DIR_SRC} ${DIR_TEST})