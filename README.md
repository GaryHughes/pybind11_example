# Overview

These are small [PyBind11](https://github.com/pybind/pybind11) examples that I've built in isolation while figuring out how to use various features while building [Python](https://www.python.org) bindings for [CrocoFIX](https://github.com/GaryHughes/crocofix).

These examples rely on the [smart_holder](https://github.com/pybind/pybind11/tree/smart_holder) branch of [PyBind11](https://github.com/pybind/pybind11). 

`git submodule add -f -b smart_holder git@github.com:pybind/pybind11 extern/pybind11`

You may need to adjust the [Python](https://www.python.org) referenced in the test scripts.

This has only been tested on macOS.

# Inheritance

This is an example of implementing an abstract C++ class in [Python](https://www.python.org) and pass that implementation back to C++ code where it will be called.

# Callable Property

This is an example of exposing a C++ class with a std::function member, exposing this member as a Python property and invoking the propery via Python->C++.

# Inherited Property

This is an example of exposing a derived C++ class with properties defined on the Python type that belong to a C++ base class.