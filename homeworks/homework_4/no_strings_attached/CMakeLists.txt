cmake_minimum_required(VERSION 3.16..3.24)
project(no_strings_attached VERSION 0.0.1 
                            DESCRIPTION "No Strings Attached homework" 
                            LANGUAGES CXX)

add_library(cxx_setup INTERFACE)
target_compile_options(cxx_setup INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(cxx_setup INTERFACE cxx_std_17)
target_include_directories(cxx_setup INTERFACE ${PROJECT_SOURCE_DIR})



include(CTest)


add_subdirectory(external)
add_subdirectory(examples)
add_subdirectory(${PROJECT_NAME})
