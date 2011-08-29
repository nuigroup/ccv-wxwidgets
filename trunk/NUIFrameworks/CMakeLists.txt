cmake_minimum_required(VERSION 2.6)
project(NUIFrameworks)

find_package(OpenCV)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/contrib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/contrib/ptypes-2.1.1/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/contrib/WOscLib-00.09")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/contrib/bitmap_munkres")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/contrib/libfidtrack")

file (GLOB source_movid "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file (GLOB source_module "${CMAKE_CURRENT_SOURCE_DIR}/src/modules/*.cpp")
file (GLOB contrib_ptype "${CMAKE_CURRENT_SOURCE_DIR}/contrib/ptypes-2.1.1/src/*.cxx")
file (GLOB contrib_wosc "${CMAKE_CURRENT_SOURCE_DIR}/contrib/WOscLib-00.09/*.cpp")
file (GLOB contrib_fidtrack "${CMAKE_CURRENT_SOURCE_DIR}/contrib/libfidtrack/*.cpp")
file (GLOB contrib_bitmap "${CMAKE_CURRENT_SOURCE_DIR}/contrib/bitmap_munkres/*.c")

add_library(movid ${source_movid} ${source_module} ${contrib_ptype} ${contrib_wosc} ${contrib_fidtrack} ${contrib_bitmap})
