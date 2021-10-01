#!/bin/sh
g++ main.cpp src/*.cpp -I include -o out.bin || exit
./out.bin
