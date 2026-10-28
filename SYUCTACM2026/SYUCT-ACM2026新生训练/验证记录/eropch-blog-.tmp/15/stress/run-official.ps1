$m = [Environment]::GetEnvironmentVariable("PATH", "Machine")
$u = [Environment]::GetEnvironmentVariable("PATH", "User")
$env:PATH = "$m;$u"
$log = 'C:/Users/Asanagi/eropch-blog/.tmp/15/stress/final.log'
& 'C:/Users/Asanagi/.codex/skills/icpc-problem-creator/scripts/run-all-tests.ps1' -Workspace 'C:/Users/Asanagi/eropch-blog/problemsets/2026syuctacm-weekly-04/problems/15' *>&1 |
    ForEach-Object { $_.ToString() } |
    Set-Content -LiteralPath $log -Encoding utf8
$code = if ($null -eq $LASTEXITCODE) { 0 } else { $LASTEXITCODE }
Add-Content -LiteralPath $log -Value ("SCRIPT_EXIT=" + $code)
Write-Host ("SCRIPT_EXIT=" + $code)
exit $code
