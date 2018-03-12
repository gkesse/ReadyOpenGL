@echo off

set PATH=C:\MinGW\bin

set GPWD=%cd%
set GMGR=..\..\manager\win

cd %GMGR%
call cmd_compile.bat
cd %GPWD%
mingw32-make
