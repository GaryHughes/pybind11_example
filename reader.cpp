#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <iostream>

namespace py = pybind11;

class reader
{
public:

    virtual ~reader() = default;

    using method_1_arg = int; 
    using method_2_arg = std::string;
    using method_3_arg = std::function<void()>;
    using method_4_arg = std::function<void(int)>;

    virtual void method_1(method_1_arg value) = 0;
    virtual void method_2(method_2_arg value) = 0;
    virtual void method_3(method_3_arg value) = 0;
    virtual void method_4(method_4_arg value) = 0;

};

class session
{
public:

    session(reader& reader)
    {
        reader.method_1(55);
        reader.method_2("string");
        reader.method_3([]() { std::cout << "method 3\n"; });
        reader.method_4([](int value) { std::cout << "method 4: " << value << "\n"; });
    }

};

class Reader : public reader
{
public:

    void method_1(method_1_arg value) override { PYBIND11_OVERRIDE_PURE(void, reader, method_1, value); }
    void method_2(method_2_arg value) override { PYBIND11_OVERRIDE_PURE(void, reader, method_2, value); }
    void method_3(method_3_arg value) override { PYBIND11_OVERRIDE_PURE(void, reader, method_3, value ); }
    void method_4(method_4_arg value) override { PYBIND11_OVERRIDE_PURE(void, reader, method_4, value ); }

};

PYBIND11_MODULE(reader, module) {

    module.doc() = "This test module";

    py::class_<reader, Reader>(module, "Reader")
        .def(py::init<>())
    ;

    py::class_<session>(module, "Session")
        .def(py::init([](reader& reader) { return std::make_shared<session>(reader); }))
    ;

}