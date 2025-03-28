@echo off
chcp 65001 > log
del log

g++ recursion.cpp -o recursion.exe

recursion.exe
