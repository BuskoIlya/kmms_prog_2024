@echo off
chcp 1251 > log
del log

set MAIN=after_refactoring_1.cpp
set EXE=after_refactoring_1.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

if exist %EXE% del %EXE%

g++ "%CHARSET%" %MAIN% -o %EXE%

%EXE%
