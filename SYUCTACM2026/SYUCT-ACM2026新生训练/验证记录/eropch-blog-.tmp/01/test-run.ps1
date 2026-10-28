param(
    [string]$Exe = "bin\main.exe",
    [string]$InputFile = "bin\t.in"
)
$psi = [System.Diagnostics.ProcessStartInfo]::new()
$psi.FileName = (Resolve-Path $Exe).Path
$psi.UseShellExecute = $false
$psi.RedirectStandardInput = $true
$psi.RedirectStandardOutput = $true
$psi.RedirectStandardError = $true
$p = [System.Diagnostics.Process]::Start($psi)
$bytes = [System.IO.File]::ReadAllBytes((Resolve-Path $InputFile).Path)
$p.StandardInput.BaseStream.Write($bytes, 0, $bytes.Length)
$p.StandardInput.BaseStream.Close()
$out = $p.StandardOutput.ReadToEnd()
$err = $p.StandardError.ReadToEnd()
$p.WaitForExit()
Write-Host "exit=$($p.ExitCode)"
Write-Host "stdout=[$out]"
if ($err) { Write-Host "stderr=[$err]" }
