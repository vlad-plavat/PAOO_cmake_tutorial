cmake_minimum_required(VERSION 3.10)

project(LaptopDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Device)

add_executable(LaptopDemo LaptopDemo.cxx)

target_link_libraries(LaptopDemo PUBLIC Laptop)

target_include_directories(LaptopDemo PUBLIC "${PROJECT_SOURCE_DIR}/Device")
