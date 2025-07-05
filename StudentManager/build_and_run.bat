@echo off
REM 通用CMake+MinGW构建与运行脚本

REM 获取当前目录名作为项目名
for %%I in ("%cd%") do set ProjectName=%%~nxI

rd /s /q build
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make

if exist %ProjectName%.exe (
    %ProjectName%.exe
) else (
    echo Build failed!
)