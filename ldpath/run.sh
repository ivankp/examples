#!/bin/bash

LD_LIBRARY_PATH=''

echo "LD_LIBRARY_PATH = $LD_LIBRARY_PATH"
echo "No rpath"
./no_rpath
echo "With rpath"
./with_rpath
echo "With runpath"
./with_runpath

echo ""

LD_LIBRARY_PATH=$PWD/lib2

echo "LD_LIBRARY_PATH = $LD_LIBRARY_PATH"
echo "No rpath"
./no_rpath
echo "With rpath"
./with_rpath
echo "With runpath"
./with_runpath

