$ErrorActionPreference = "Continue"
$env:PATH = ((($env:PATH -split ";") | Where-Object { $_ -and ($_ -notmatch [regex]::Escape("Program Files\Git\mingw64")) }) -join ";")

$script = "C:/Users/Asanagi/.codex/skills/icpc-problem-creator/scripts/run-all-tests.ps1"
$ws = "C:/Users/Asanagi/eropch-blog/problemsets/2026syuctacm-weekly-04/problems/07"
$log = "C:/Users/Asanagi/eropch-blog/.tmp/07/verify/run5.log"

& $script -Workspace $ws *> $log
$ok = $?
$code = if ($null -eq $LASTEXITCODE) { if ($ok) { 0 } else { 1 } } else { $LASTEXITCODE }

"OK=$ok CODE=$code" | Out-File -Encoding ascii "C:/Users/Asanagi/eropch-blog/.tmp/07/verify/exitcode.txt"
if (-not $ok) { exit 1 }
exit $code
