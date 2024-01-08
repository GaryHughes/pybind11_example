# Overview
This is an example of using [PyBind11](https://github.com/pybind/pybind11) to implement an abstract C++ class in [Python](https://www.python.org) and pass that implementation back to C++ code where it will be called. I used this as a test bed to learn how to do this while building [Python](https://www.python.org) bindings for [CrocoFIX](https://github.com/GaryHughes/crocofix).

This relies on the [smart_holder](https://github.com/pybind/pybind11/tree/smart_holder) branch of [PyBind11](https://github.com/pybind/pybind11). 

`git submodule add -f -b smart_holder ../../pybind/pybind11 extern/pybind11`

You may need to adjust the [Python](https://www.python.org) referenced in the test script.

This has only been tested on macOS.