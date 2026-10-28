param(
    [string]$Root = "C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04\problems",
    [string]$OutDir = "C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\logs",
    [string[]]$Only = @()
)

$env:PATH = "C:\Algo Bootstrap\mingw64\bin;" + $env:PATH
$runner = "C:\Users\Asanagi\.codex\skills\icpc-problem-creator\scripts\run-all-tests.ps1"
New-Item -ItemType Directory -Path $OutDir -Force | Out-Null

$ids = if ($Only.Count -gt 0) { $Only } else { 1..25 | ForEach-Object { "{0:D2}" -f $_ } }
$results = @()

foreach ($id in $ids) {
    $ws = Join-Path $Root $id
    $log = Join-Path $OutDir "verify-$id.log"
    $sw = [System.Diagnostics.Stopwatch]::StartNew()
    & pwsh -NoProfile -File $runner -Workspace $ws *> $log
    $code = $LASTEXITCODE
    $sw.Stop()

    $lines = Get-Content -LiteralPath $log -ErrorAction SilentlyContinue
    $errs = @($lines | Where-Object { $_ -match '^\[(\w+)\]\[error\]' })
    $succ = @($lines | Where-Object { $_ -match '^\[success\]' })
    $results += [pscustomobject]@{
        Id      = $id
        Exit    = $code
        Secs    = [math]::Round($sw.Elapsed.TotalSeconds, 1)
        Errors  = $errs.Count
        Success = if ($succ.Count -gt 0) { $succ[-1] } else { "" }
    }
    Write-Host ("{0}  exit={1}  {2}s  errors={3}" -f $id, $code, [math]::Round($sw.Elapsed.TotalSeconds,1), $errs.Count)
    foreach ($e in $errs) { Write-Host ("    " + $e) }
}

$results | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $OutDir "summary.json") -Encoding utf8
Write-Host ""
Write-Host "==== SUMMARY ===="
$results | Format-Table -AutoSize | Out-String -Width 200
Write-Host ("PASS: " + @($results | Where-Object { $_.Exit -eq 0 }).Count + " / " + $results.Count)
