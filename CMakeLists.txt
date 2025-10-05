cmake_minimum_required(VERSION 4.1.2)
project ("Game")

if (WIN32)
	#include_directories(./vcpkg_installed/x64-windows/include)
endif()

if (APPLE)
endif()

include_directories(./include)


find_package(SDL3 REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_library(Framework STATIC src/framework.cpp)

add_executable(Game src/main.cpp )
target_link_libraries(Game PRIVATE fmt::fmt SDL3::SDL3 Framework)