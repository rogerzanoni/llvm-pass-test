#!/bin/sh

cd hello
make clean
make

cd ../hellopass
cmake .
make
cd ..

opt -load hellopass/libhellopass.so -hello -helloblock < hello/hello.bc > /dev/null
