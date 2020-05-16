include_directories(include)
include_directories(src)

file(GLOB_RECURSE ann_files *.cpp *.h)
add_library(ann ${ann_files})
