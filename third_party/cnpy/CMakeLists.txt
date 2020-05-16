find_package(ZLIB REQUIRED)

include_directories(${ZLIB_INCLUDE_DIRS})

add_library(cnpy cnpy.cpp)
target_link_libraries(cnpy ${ZLIB_LIBRARIES})
