cmake_minimum_required(VERSION 3.18.2)
project(PAT_BASIC)

aux_source_directory(src DIR_SRC)
foreach(F ${DIR_SRC})
	string (REGEX REPLACE "src/([0-9]+)\\.cpp$" "\\1" F_NAME ${F})
	add_executable(${F_NAME} ${F})
endforeach(F)