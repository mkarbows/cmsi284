#!/bin/bash

clear

nasm -felf64 calc-ops.asm

gcc calc-ops.o add.c -o add

gcc calc-ops.o subtract.c -o subtract

gcc calc-ops.o gcd.c -o gcd

echo To call each function say [add, subtract, gcd] {arg1} {arg2}
