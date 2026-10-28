@echo off
type ok.in | "C:\Users\Asanagi\.codex\skills\icpc-problem-creator\.codex-test-artifacts\build\04-16\bin\validator.exe"
echo VALIDATOR_EXIT=%errorlevel%
