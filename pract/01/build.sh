#!/bin/bash
if [ ! -e build-linux ]; then
	mkdir build-linux
fi
if [ -e main.c ]; then
	g++ main.c -o ./build-linux/main
	if [ $? -eq 0 ]; then
		./build-linux/main
	fi
fi