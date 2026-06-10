#!/bin/bash

if [ ! -e build-linux ]; then
	mkdir build-linux
fi
if [ ! -e build-linux/std.o ]; then
	g++ -std=c++23 -fmodules -fsearch-include-path -c bits/std.cc -o build-linux/std.o
fi

read -p "что билдим?" FNAME
if [ ! -e "$FNAME.cpp" ]; then
	echo "no."
else
	g++ -std=c++23 -fmodules "$FNAME.cpp" build-linux/std.o -o build-linux/$FNAME 
	if [ $? -eq 0  ]; then
		"./build-linux/$FNAME"
	fi
fi
