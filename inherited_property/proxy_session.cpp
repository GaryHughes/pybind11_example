#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;

class session
{
public:

    const std::string& begin_string() const noexcept { return m_begin_string; }
    void begin_string(const std::string& begin_string) { m_begin_string = begin_string; }    

private:

    std::string m_begin_string;

};

class proxy_session : public session
{
};

PYBIND11_MODULE(fix, module) {

    module.doc() = "This test module";

    py::class_<session>(module, "Session")
        .def(py::init<>([](){
            return std::make_shared<proxy_session>();
        }))
        .def_property("BeginString", 
                      static_cast<const std::string&(session::*)()const>(&session::begin_string), 
                      static_cast<void(session::*)(const std::string&)>(&session::begin_string))
    ;
  
}
