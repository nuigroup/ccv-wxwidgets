cmake_minimum_required(VERSION 2.6)
project(CCV)

find_package(wxWidgets)
find_package(OpenCV)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../NUIFrameworks/src")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../NUIFrameworks/contrib/ptypes-2.1.1/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/contrib/tinyxml")
include(${wxWidgets_USE_FILE})

file (GLOB source_ccv "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(ccv2 ${source_ccv})
target_link_libraries(ccv2 ${wxWidgets_LIBRARIES} ${OpenCV_LIBS} "${CMAKE_CURRENT_BINARY_DIR}/../NUIFrameworks/libmovid.a")

