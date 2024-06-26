cmake_minimum_required(VERSION 3.20.0)
project(mlir-choco LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to conform to")
find_package(MLIR REQUIRED CONFIG)
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


# Needed so that docs are generted in the build dir,
# otherwise there is an attempt to create docs folder in /
set(MLIR_BINARY_DIR ${CMAKE_BINARY_DIR})


include(AddLLVM)
include(TableGen)


list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
include(AddMLIR)
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
include_directories("./")
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory(include)
add_subdirectory(codegen)
add_subdirectory(dialect)
add_subdirectory(tools)
add_subdirectory(lowering)
