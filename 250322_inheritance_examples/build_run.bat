@echo off
chcp 65001 > log
del log

set NAME=inheritance_examples
set EXE=%NAME%.exe

if exist %EXE% del %EXE%

set SOURCES="%NAME%.cpp"

g++ "%SOURCES%" -o %EXE%

%EXE%
