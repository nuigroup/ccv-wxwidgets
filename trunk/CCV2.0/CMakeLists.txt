cmake_minimum_required(VERSION 2.6)
project(CCV)

find_package(OpenCV)
find_package(wxWidgets)

file (GLOB source_ccv "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(ccv2 ${source_ccv})

