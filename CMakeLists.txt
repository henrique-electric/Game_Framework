cmake_minimum_required(VERSION 4.1.2)
project ("Game")

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third/SDL)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third/SDL_image)

if (WIN32)
	#include_directories(./vcpkg_installed/x64-windows/include)
endif()

if (APPLE)
	
endif()

include_directories(./include)


find_package(SDL3 REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(SDL3_image REQUIRED)

add_library(Framework STATIC src/framework.cpp)

add_executable(Game src/main.cpp )
target_link_libraries(Game PRIVATE fmt::fmt SDL SDL_image Framework)