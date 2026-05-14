# Node.js Automatic Installation Script
# For Windows Systems

Write-Host "Starting Node.js installation..." -ForegroundColor Green

# Check if running with administrator privileges
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
if (-not $isAdmin) {
    Write-Host "Warning: It is recommended to run this script with administrator privileges to ensure proper installation" -ForegroundColor Yellow
}

# Method 1: Direct download and install Node.js LTS version
try {
    Write-Host "Downloading Node.js LTS version..." -ForegroundColor Cyan
    
    # Get the latest LTS version download link
    $downloadUrl = "https://nodejs.org/dist/latest-v20.x/node-v20.18.0-win-x64.msi"
    $installerPath = "$env:TEMP\nodejs-installer.msi"
    
    # Download installer
    Invoke-WebRequest -Uri $downloadUrl -OutFile $installerPath -UseBasicParsing
    
    Write-Host "Download complete, starting installation..." -ForegroundColor Cyan
    
    # Silent installation
    Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", $installerPath, "/quiet", "/norestart" -Wait
    
    Write-Host "Node.js installation completed!" -ForegroundColor Green
    
    # Clean up installer file
    Remove-Item $installerPath -Force
    
} catch {
    Write-Host "Direct installation failed, trying Chocolatey..." -ForegroundColor Yellow
    
    # Method 2: Install using Chocolatey
    try {
        # Check if Chocolatey is installed
        if (!(Get-Command choco -ErrorAction SilentlyContinue)) {
            Write-Host "Installing Chocolatey..." -ForegroundColor Cyan
            Set-ExecutionPolicy Bypass -Scope Process -Force
            [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
            Invoke-Expression ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
        }
        
        Write-Host "Installing Node.js via Chocolatey..." -ForegroundColor Cyan
        choco install nodejs -y
        
    } catch {
        Write-Host "Chocolatey installation also failed, please install Node.js manually" -ForegroundColor Red
        Write-Host "Please visit https://nodejs.org to download and install the LTS version" -ForegroundColor Yellow
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
    
    Write-Host "Installation successful!" -ForegroundColor Green
    Write-Host "Node.js version: $nodeVersion"
    Write-Host "npm version: $npmVersion"  
    Write-Host "npx version: $npxVersion"
    
    # Test context7-mcp
    Write-Host "Testing context7-mcp..." -ForegroundColor Cyan
    npx -y @upstash/context7-mcp@latest
    
} catch {
    Write-Host "Verification failed, please restart your terminal and try again" -ForegroundColor Red
    Write-Host "Error message: $($_.Exception.Message)" -ForegroundColor Yellow
}

Write-Host "Script execution completed!" -ForegroundColor Green