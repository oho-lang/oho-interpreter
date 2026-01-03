cmake_minimum_required(VERSION 3.20)
project(oho_lang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS   OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SRC_FILES src/*.cpp)

add_executable(oho-lang ${SRC_FILES})

target_compile_options(oho-lang PRIVATE
    $<$<CONFIG:Debug>:   -O0 -g>
    $<$<CONFIG:Release>: -O3 -DNDEBUG>
)