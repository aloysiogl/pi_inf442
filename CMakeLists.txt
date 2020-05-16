project(pi_inf442)
cmake_minimum_required(VERSION 3.10)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_definitions(-g -O3 -std=c++11 -Wall -Wextra)
set(CMAKE_CXX_COMPILER g++)
set (CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
include_directories(src)
include_directories(third_party)

add_subdirectory(third_party/ann_1.1.2)
add_subdirectory(third_party/cnpy)

file(GLOB_RECURSE src src/*.cpp src/*.h)
add_library(src ${src})
target_link_libraries(src ann Eigen3::Eigen cnpy)

file(GLOB scripts scripts/*.cpp)
foreach (file ${scripts})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
    target_link_libraries(${name} src)
endforeach (file ${scripts})