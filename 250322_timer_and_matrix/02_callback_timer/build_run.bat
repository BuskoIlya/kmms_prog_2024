@echo off
chcp 65001 > log
del log

set NAME=callback_timer_test
set EXE=%NAME%.exe

if exist %EXE% del %EXE%

set SOURCES="main.cpp"

g++ "%SOURCES%" -o %EXE%

%EXE%
