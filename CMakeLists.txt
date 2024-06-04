cmake_minimum_required(VERSION 3.17.0)

project(pybind11_examples)

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)

add_subdirectory(extern/pybind11)

include_directories(
    "extern/pybind11/include"
)

add_definitions(-DPYBIND11_USE_SMART_HOLDER_AS_DEFAULT)

add_subdirectory(inheritance)
add_subdirectory(callable_property)