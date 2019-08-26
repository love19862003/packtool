@echo off
rem svn --version && echo svn found||goto ERROR_CONTEXT

setlocal enabledelayedexpansion

rem svn info ./ > tem.txt
rem for /f"delims=" %%a in ('findstr "Revision:" tem.txt') do (set svnState=%%a)
rem set version=%svnState:~10%

set version=4096
echo svn version : %version%

.\debug\tool.exe .\setting.xlsx v1.0.0.%version% 1

if errorlevel 1 goto ERROR_DATA
echo pack excel success

pause
exit

:ERROR_CONTEXT
color 2f
echo please install svn for command line
pause 
exit

:ERROR_DATA
color 2f
echo pack failed, please check data
pause 
exit