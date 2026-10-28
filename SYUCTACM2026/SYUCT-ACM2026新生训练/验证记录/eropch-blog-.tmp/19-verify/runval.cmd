@echo off
type t.in | validator.exe
exit /b %errorlevel%
