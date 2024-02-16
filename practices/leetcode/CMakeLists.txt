_setup_project_env("leetcode")
project(${_PROJECT_NAME} LANGUAGES CXX)

find_package(GTest CONFIG REQUIRED)
#target_link_libraries(main PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

set("_OBJS" "")
set("_LIBS" "")

function(_add_subdirectories _SUBDIRECOTRY)
    # add project
    get_filename_component("_SUB_PROJ_NAME" ${_SUBDIRECOTRY} NAME)
    _setup_project_env(${_SUB_PROJ_NAME})
    project(${_PROJECT_NAME} LANGUAGES CXX)

    #add sources
    aux_source_directory("${_SUBDIRECOTRY}/src" "_SUB_SRC")
    add_library(${PROJECT_NAME} OBJECT ${_SUB_SRC} "${_SUBDIRECOTRY}/tests/main.cpp")
    add_library(${_PROJECT_NAMESPACE} ALIAS ${PROJECT_NAME})
    target_include_directories(${PROJECT_NAME} PUBLIC "${_SUBDIRECOTRY}/src")
    target_link_libraries(${PROJECT_NAME} PUBLIC GTest::gtest GTest::gtest_main GTest::gmock)

    # set properties
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

    # add objests to variables
    list(APPEND "_OBJS" $<TARGET_OBJECTS:${_PROJECT_NAMESPACE}>)
    set("_OBJS" ${_OBJS} PARENT_SCOPE)
    list(APPEND "_LIBS" ${_PROJECT_NAMESPACE})
    set("_LIBS" ${_LIBS} PARENT_SCOPE)
endfunction(_add_subdirectories)


# add add all subdirectories
file(GLOB _SUBDIRECOTRY_LIST LIST_DIRECTORIES TRUE "libs/*")
foreach(_SUBDIRECOTRY IN LISTS _SUBDIRECOTRY_LIST)
    # use function for get into a temp variable scope to run `_setup_project_env()`
    _add_subdirectories(${_SUBDIRECOTRY})
endforeach()



# temporarily useless
add_library(${PROJECT_NAME} STATIC ${_OBJS})
add_library(${_PROJECT_NAMESPACE} ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PUBLIC ${_LIBS})

# for gtest
add_executable(${PROJECT_NAME}_tests ${_OBJS})
add_executable(${_PROJECT_NAMESPACE}::tests ALIAS ${PROJECT_NAME}_tests)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${_LIBS})