cmake_minimum_required (VERSION 2.6)
project (Lab2)
add_executable(oop_exercise_02
Lab2.cpp
logika.cpp)

set(CMAKE_CXX_FLAGS
	"${CMAKE_CXX_FLAGS} -Wall -Wextra")
