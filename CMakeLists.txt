cmake_minimum_required(VERSION 3.18)

project(CiphrProject)

enable_language(CXX)

# configure c++ standard
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CONAN_USE_CMAKE_GENERATOR OFF CACHE BOOL "Whether use \"cmake\" generator or \"conan_paths\" generator")

if(CONAN_USE_CMAKE_GENERATOR)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif()

# find Qt packages (both "conan_paths" generator and "cmake" generator provide appropriate settings here)
find_package(Qt5 5.15.0 EXACT REQUIRED COMPONENTS Qml Quick LinguistTools)

if(NOT CONAN_USE_CMAKE_GENERATOR)
    find_package(OpenSSL REQUIRED)
endif()

# Internal libraries
add_subdirectory(rand-lib)

# Internal applications
add_subdirectory(ui-app)
