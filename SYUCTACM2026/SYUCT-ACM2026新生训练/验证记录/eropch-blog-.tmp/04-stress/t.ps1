$env:PATH = (Get-Command g++).Source | Split-Path -Parent
& 'C:\Users\Asanagi\.codex\skills\icpc-problem-creator\scripts\run-all-tests.ps1' -Workspace 'problemsets/2026syuctacm-weekly-04/problems/04'
