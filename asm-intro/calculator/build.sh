#!/bin/bash

clear

nasm -felf64 calc-ops.asm

gcc calc-ops.o addition.c -o addition

gcc calc-ops.o subtract.c -o subtract

gcc calc-ops.o gcd.c -o gcd

echo To call each function say [addition, subtract, gcd] {arg1} {arg2}
