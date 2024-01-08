#!/opt/homebrew/bin/python3.12

from reader import *

class SocketReader(Reader):

    def method_1(self, value):
        print('SocketReader.method_1 {}'.format(value))

    def method_2(self, value):
        print('SocketReader.method_2 {}'.format(value))

    def method_3(self, value):
        print('SocketReader.method_3')
        value()

    def method_4(self, value):
        print('SocketReader.method_4')
        value(666)


if __name__ == "__main__":
    reader = SocketReader()
    session = Session(reader)
