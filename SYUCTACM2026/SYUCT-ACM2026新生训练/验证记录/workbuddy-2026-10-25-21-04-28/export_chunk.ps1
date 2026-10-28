param(
    [Parameter(Mandatory = $true)][string[]]$Ids
)

$env:PATH = "C:\Algo Bootstrap\mingw64\bin;" + $env:PATH
$exporter = 'C:\Users\Asanagi\.codex\skills\icpc-problem-creator\scripts\export-hydrozip.ps1'
$base = 'C:\Users\Asanagi\eropch-blog\problemsets\2026syuctacm-weekly-04'
$outDir = Join-Path $base 'hydro'
New-Item -ItemType Directory -Path $outDir -Force | Out-Null

foreach ($id in $Ids) {
    $ws = Join-Path (Join-Path $base 'problems') $id
    $out = Join-Path $outDir ($id + '.zip')
    $log = Join-Path 'C:\Users\Asanagi\WorkBuddy\2026-10-25-21-04-28\logs' ('export-' + $id + '.log')
    & pwsh -NoProfile -File $exporter -Workspace $ws -Output $out *> $log
    $code = $LASTEXITCODE
    $size = if (Test-Path $out) { (Get-Item $out).Length } else { 0 }
    Write-Host ("{0} export exit={1} size={2}" -f $id, $code, $size)
    if ($code -ne 0) {
        Get-Content $log -Tail 12 | ForEach-Object { Write-Host ("    " + $_) }
    }
}
