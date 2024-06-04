#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <iostream>
#include <functional>

namespace py = pybind11;

using log_callback = std::function<void(const std::string&)>;

class session
{
public:

    log_callback information_callback;
    log_callback warning_callback;

    void invoke_information_callback(const std::string& message)
    {
        information_callback(message);
    }

    void invoke_warning_callback(const std::string& message)
    {
        warning_callback(message);
    }

};

PYBIND11_MODULE(session, module) {

    module.doc() = "This test module";

    py::class_<session>(module, "Session")
        .def(py::init<>())
        .def_readwrite("information", &session::information_callback)
        .def_readwrite("warning", &session::warning_callback)
        .def("invoke_information_callback", &session::invoke_information_callback)
        .def("invoke_warning_callback", &session::invoke_warning_callback)
    ;
  
}
