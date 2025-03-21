@echo off
chcp 65001 > log
del log

set NAME=inheritance_and_timers_test
set EXE=%NAME%.exe

if exist %EXE% del %EXE%

set SOURCES="main.cpp"

g++ -O0 "%SOURCES%" -o %EXE%

%EXE%
