$ErrorActionPreference = "Stop"
$cmd = Join-Path (Get-Location) "wrap.cmd"
$text = "@echo off`r`n`"$(Join-Path (Get-Location) 'sol.exe')`" < `"$(Join-Path (Get-Location) 't.in')`"`r`n"
[System.IO.File]::WriteAllText($cmd, $text, [System.Text.Encoding]::ASCII)
$psi = [System.Diagnostics.ProcessStartInfo]::new()
$psi.FileName = $env:ComSpec
$psi.UseShellExecute = $false
$psi.RedirectStandardOutput = $true
$psi.RedirectStandardError = $true
[void]$psi.ArgumentList.Add("/d")
[void]$psi.ArgumentList.Add("/c")
[void]$psi.ArgumentList.Add($cmd)
$p = [System.Diagnostics.Process]::new()
$p.StartInfo = $psi
[void]$p.Start()
$o = $p.StandardOutput.ReadToEnd()
$e = $p.StandardError.ReadToEnd()
$p.WaitForExit()
Write-Host "EXIT=$($p.ExitCode) OUT=[$o] ERR=[$e]"
