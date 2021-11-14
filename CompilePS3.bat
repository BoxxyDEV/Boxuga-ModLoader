@echo off
cd %~dp0

:start
echo Compile Xbox Ver of Boxuga Loader

echo Press ENTER to launch

pause > nul

cls
"../../bin/SC-CL.exe" -platform=PS3 -target=GTAV -out-dir="GTAV/PS3/" ModLoader.c ../../include/common.c -- -I "../../include/"

goto start
