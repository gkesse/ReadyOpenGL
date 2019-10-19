@echo off

set PATH=C:\MinGW\bin
set PATH=C:\Users\Admin\Downloads\Programs\ReadyLib\dev\sqlite\mingw64\bin;%PATH%

echo.
..\code\GProject\Release\GProject.exe %*
echo.

::pause
