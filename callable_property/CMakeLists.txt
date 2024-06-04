pybind11_add_module(session session.cpp)

set_target_properties(session PROPERTIES SUFFIX ".so")
