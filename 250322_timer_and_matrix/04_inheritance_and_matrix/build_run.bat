@echo off
chcp 65001 > log
del log

set NAME=main
set EXE=%NAME%.exe

if exist %EXE% del %EXE%

set SOURCES="%NAME%.cpp matrix.cpp cache_optimized_matrix.cpp"

g++ "%SOURCES%" -o %EXE%

%EXE%
