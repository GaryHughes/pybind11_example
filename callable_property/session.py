#!/usr/bin/python3

from session import *

def on_warning(message):
    print("on_warning: " + message)

if __name__ == "__main__":
    session = Session()
    session.information = lambda message: print("on_information: " + message)
    session.warning = on_warning
    session.invoke_information_callback("Bart Simpson")
    session.invoke_warning_callback("Nelson Muntz")
