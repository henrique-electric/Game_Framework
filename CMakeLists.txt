cmake_minimum_required(VERSION 4.1.2)
project ("Game")

set(CMAKE_CXX_STANDARD 23)
include(FetchContent)


FetchContent_Declare(
  SDL
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG        a8589a84226a6202831a3d49ff4edda4acab9acd # release-1.10.0
)

FetchContent_Declare(
	SDL_image
	GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
 	GIT_TAG 	   11154afb7855293159588b245b446a4ef09e574f
)

FetchContent_MakeAvailable(SDL)
FetchContent_MakeAvailable(SDL_image)

if (WIN32)
	#include_directories(./vcpkg_installed/x64-windows/include)
endif()

if (APPLE)
	
endif()

include_directories(./include)


add_library(Framework STATIC src/framework.cpp)
target_link_libraries(Framework PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)

add_executable(Game src/main.cpp)
target_link_libraries(Game PRIVATE Framework)
