pybind11_add_module(fix proxy_session.cpp)

set_target_properties(fix PROPERTIES SUFFIX ".so")
