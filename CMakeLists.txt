cmake_minimum_required(VERSION 3.16)

project(VC_lab_04_aa25-26 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS} include config)

set(EIGEN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(srimg++ SHARED
        src/utils.cpp
        src/load_image.cpp

        src/process_image.cpp
        src/resize_image.cpp
        src/filter_image.cpp

        src/harris_image.cpp
        src/panorama_image.cpp

        src/matrix.cpp
        )

link_libraries(srimg++ m stdc++)

add_executable(test4 src/test/test4.cpp)
target_link_libraries(test4 ${Boost_LIBRARIES})
add_executable(integration_test src/test/integration.cpp)
add_executable(make-panorama src/test/make-panorama.cpp)

add_subdirectory(src/opencv)