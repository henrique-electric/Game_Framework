# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project ("Game")

if (WIN32)
	set(CMAKE_TOOLCHAIN_FILE "C:\\SDKs\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")
endif()

if (UNIX)
	set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

include_directories(./include)
include_directories(./vcpkg_installed/x64-windows/include)

find_package(sdl3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)


add_executable(Game src/main.cpp)
target_link_libraries(Game PRIVATE SDL3::SDL3)