$ErrorActionPreference = "Stop"
$out = & "./sol.exe" < "t.in"
Write-Host "RAW=[" + ($out -join "|") + "]"
