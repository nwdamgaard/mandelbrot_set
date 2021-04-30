cmake_minimum_required(VERSION 3.10)

SET (SRC "../Mandelbrot_Set")

project(Mandelbrot)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories("${SRC}")
add_executable(Mandelbrot ${SRC}/ComplexNumbers.cpp ${SRC}/Mandelbrot_Set.cpp ${SRC}/pch.cpp)
target_link_libraries(Mandelbrot ${SDL2_LIBRARIES})
