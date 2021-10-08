#!/bin/bash
g++ main.cpp src/* -I include -o out.bin || exit
./out.bin
