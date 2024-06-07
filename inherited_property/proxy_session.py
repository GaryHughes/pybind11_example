#!/usr/bin/python3

from fix import *

if __name__ == "__main__":
    session = Session()
    session.BeginString = "FIXT1.1"
    print(type(session))
    value = session.BeginString
    print(value)