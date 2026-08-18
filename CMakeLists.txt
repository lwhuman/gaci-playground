cmake_minimum_required(VERSION 3.23)

project(gaci-test 
        VERSION 1.0.0
        LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build tests" ON)

file(GLOB_RECURSE LIB_SRC ${PROJECT_SOURCE_DIR}/src/*.c*)

add_library(
    mymath
    ${LIB_SRC}
)

target_include_directories(
    mymath
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# target_link_libraries(
#     mymath
#     PRIVATE
#     m
# )

function(add_test_executable SRC_FILE)
    get_filename_component(TARGET_NAME ${SRC_FILE} NAME_WE)
    add_executable(
        ${TARGET_NAME}
        ${PROJECT_SOURCE_DIR}/tests/${SRC_FILE}
    )
    target_link_libraries(
        ${TARGET_NAME}
        PRIVATE
        mymath
    )
    add_test(
        NAME ${TARGET_NAME}
        COMMAND ${TARGET_NAME}
    )
endfunction()

if (BUILD_TESTS)
    enable_testing()
    add_test_executable(test1.c)
endif (BUILD_TESTS)
