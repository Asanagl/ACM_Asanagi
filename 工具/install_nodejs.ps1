# Node.js 自动安装脚本
# 适用于 Windows 系统

Write-Host "开始安装 Node.js..." -ForegroundColor Green

# 检查是否以管理员权限运行
$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
if (-not $isAdmin) {
    Write-Host "警告: 建议以管理员权限运行此脚本以确保正确安装" -ForegroundColor Yellow
}

# 方法1: 直接下载并安装 Node.js LTS 版本
try {
    Write-Host "正在下载 Node.js LTS 版本..." -ForegroundColor Cyan
    
    # 获取最新的 LTS 版本下载链接
    $downloadUrl = "https://nodejs.org/dist/latest-v20.x/node-v20.18.0-win-x64.msi"
    $installerPath = "$env:TEMP\nodejs-installer.msi"
    
    # 下载安装包
    Invoke-WebRequest -Uri $downloadUrl -OutFile $installerPath -UseBasicParsing
    
    Write-Host "下载完成，开始安装..." -ForegroundColor Cyan
    
    # 静默安装
    Start-Process -FilePath "msiexec.exe" -ArgumentList "/i", $installerPath, "/quiet", "/norestart" -Wait
    
    Write-Host "Node.js 安装完成!" -ForegroundColor Green
    
    # 清理安装文件
    Remove-Item $installerPath -Force
    
} catch {
    Write-Host "直接安装失败，尝试使用 Chocolatey..." -ForegroundColor Yellow
    
    # 方法2: 使用 Chocolatey 安装
    try {
        # 检查是否安装了 Chocolatey
        if (!(Get-Command choco -ErrorAction SilentlyContinue)) {
            Write-Host "正在安装 Chocolatey..." -ForegroundColor Cyan
            Set-ExecutionPolicy Bypass -Scope Process -Force
            [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
            Invoke-Expression ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
        }
        
        Write-Host "使用 Chocolatey 安装 Node.js..." -ForegroundColor Cyan
        choco install nodejs -y
        
    } catch {
        Write-Host "Chocolatey 安装也失败了，请手动安装 Node.js" -ForegroundColor Red
        Write-Host "请访问 https://nodejs.org 下载并安装 LTS 版本" -ForegroundColor Yellow
        exit 1
    }
}

# 刷新环境变量
Write-Host "刷新环境变量..." -ForegroundColor Cyan
$env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")

# 验证安装
Write-Host "验证安装..." -ForegroundColor Cyan
try {
    $nodeVersion = & "node" "--version"
    $npmVersion = & "npm" "--version"
    $npxVersion = & "npx" "--version"
    
    Write-Host "安装成功!" -ForegroundColor Green
    Write-Host "Node.js 版本: $nodeVersion"
    Write-Host "npm 版本: $npmVersion"  
    Write-Host "npx 版本: $npxVersion"
    
    # 测试 context7-mcp
    Write-Host "测试 context7-mcp..." -ForegroundColor Cyan
    npx -y @upstash/context7-mcp@latest
    
} catch {
    Write-Host "验证失败，请重启终端后重试" -ForegroundColor Red
    Write-Host "错误信息: $($_.Exception.Message)" -ForegroundColor Yellow
}

Write-Host "脚本执行完成!" -ForegroundColor Green