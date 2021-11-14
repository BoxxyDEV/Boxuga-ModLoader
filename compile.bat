@echo off
cd %~dp0

:start
echo Compile Xbox Ver of Boxuga Loader

echo Press ENTER to launch

pause > nul

cls
"../../bin/SC-CL.exe" -platform=X360 -target=GTAV -out-dir="GTAV/X360/bin/" ModLoader.c ../../include/common.c -- -I "../../include/"

goto start
