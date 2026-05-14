# Simple Node.js Installation Script

Write-Host "Starting Node.js installation..." -ForegroundColor Green

# Try direct download first
try {
    Write-Host "Downloading Node.js..." -ForegroundColor Cyan
    
    $downloadUrl = "https://nodejs.org/dist/latest-v20.x/node-v20.18.0-win-x64.msi"
    $installerPath = "$env:TEMP\nodejs-installer.msi"
    
    Invoke-WebRequest -Uri $downloadUrl -OutFile $installerPath -UseBasicParsing
    
    Write-Host "Installing Node.js..." -ForegroundColor Cyan
    Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", $installerPath, "/quiet", "/norestart" -Wait
    
    Write-Host "Installation completed!" -ForegroundColor Green
    Remove-Item $installerPath -Force
    
} catch {
    Write-Host "Direct installation failed, trying Chocolatey..." -ForegroundColor Yellow
    
    # Try Chocolatey
    try {
        if (!(Get-Command choco -ErrorAction SilentlyContinue)) {
            Write-Host "Installing Chocolatey..." -ForegroundColor Cyan
            Set-ExecutionPolicy Bypass -Scope Process -Force
            [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
            Invoke-Expression ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
        }
        
        Write-Host "Installing Node.js via Chocolatey..." -ForegroundColor Cyan
        choco install nodejs -y
        
    } catch {
        Write-Host "Please manually install Node.js from https://nodejs.org" -ForegroundColor Red
        exit 1
    }
}

# Refresh environment variables
Write-Host "Refreshing environment variables..." -ForegroundColor Cyan
$env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")

# Verify installation
Write-Host "Verifying installation..." -ForegroundColor Cyan
try {
    $nodeVersion = & "node" "--version"
    $npmVersion = & "npm" "--version"
    $npxVersion = & "npx" "--version"
    
    Write-Host "Success!" -ForegroundColor Green
    Write-Host "Node.js version: $nodeVersion"
    Write-Host "npm version: $npmVersion"  
    Write-Host "npx version: $npxVersion"
    
} catch {
    Write-Host "Verification failed, please restart your terminal" -ForegroundColor Red
}

Write-Host "Script completed!" -ForegroundColor Green