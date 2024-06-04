pybind11_add_module(reader reader.cpp)

set_target_properties(reader PROPERTIES SUFFIX ".so")
