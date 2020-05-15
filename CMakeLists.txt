project(pi_inf442)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
include_directories(src)

file(GLOB_RECURSE src src/*.cpp src/*.h)
add_library(src ${src})

file(GLOB scripts scripts/*.cpp)
foreach (file ${scripts})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
    target_link_libraries(${name} src)
endforeach (file ${scripts})