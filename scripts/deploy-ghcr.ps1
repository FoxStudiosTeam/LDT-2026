<#
.SYNOPSIS
    Скрипт ручной сборки и деплоя Docker-образов в GitHub Container Registry (ghcr.io).

.DESCRIPTION
    Собирает образы контейнеров проекта LDT-2026 и загружает их в ghcr.io/foxstudiosteam/ldt-2026/...

.PARAMETER Target
    Какой контейнер собирать (all, rust_viewer, rail_tuner_2d, rust_error_listener, ros2_stream_player, ros2_dataset_player).
    По умолчанию: all.

.PARAMETER Tag
    Тег образа (по умолчанию: latest).

.EXAMPLE
    .\scripts\deploy-ghcr.ps1
    .\scripts\deploy-ghcr.ps1 -Target rust_viewer -Tag v1.0.0
#>

param (
    [ValidateSet("all", "rust_viewer", "rail_tuner_2d", "rust_error_listener", "ros2_stream_player", "ros2_dataset_player")]
    [string]$Target = "all",

    [string]$Tag = "latest"
)

$ErrorActionPreference = "Stop"

$REGISTRY = "ghcr.io/foxstudiosteam/ldt-2026"

Write-Host "==========================================================" -ForegroundColor Cyan
Write-Host "📦 GHCR Image Deployer: $REGISTRY" -ForegroundColor Cyan
Write-Host "Target: $Target | Tag: $Tag" -ForegroundColor Cyan
Write-Host "==========================================================" -ForegroundColor Cyan

# Проверка авторизации в docker
$dockerConfig = "$env:USERPROFILE\.docker\config.json"
$isLoggedIn = $false
if (Test-Path $dockerConfig) {
    $content = Get-Content $dockerConfig -Raw
    if ($content -match "ghcr.io") {
        $isLoggedIn = $true
    }
}

if (-not $isLoggedIn) {
    Write-Host "⚠️ Вы не авторизованы в ghcr.io!" -ForegroundColor Yellow
    Write-Host "Для авторизации выполните:" -ForegroundColor Yellow
    Write-Host "  echo `$CR_PAT | docker login ghcr.io -u <GITHUB_USERNAME> --password-stdin" -ForegroundColor White
    $reply = Read-Host "Хотите войти сейчас? (y/N)"
    if ($reply -eq 'y' -or $reply -eq 'Y') {
        $username = Read-Host "Введите ваш GitHub Username"
        docker login ghcr.io -u $username
    } else {
        Write-Host "Продолжаем сборку без автоматического логина..." -ForegroundColor Gray
    }
}

$services = @(
    @{ Name = "rust_viewer";          Dockerfile = "./rust_listener/Dockerfile";     Context = "." },
    @{ Name = "rail_tuner_2d";        Dockerfile = "./rail_tuner_2d/Dockerfile";     Context = "." },
    @{ Name = "rust_error_listener";  Dockerfile = "./test_error_listener/Dockerfile"; Context = "." },
    @{ Name = "ros2_stream_player";   Dockerfile = "./bag_player/Dockerfile";        Context = "." },
    @{ Name = "ros2_dataset_player";  Dockerfile = "./dataset/Dockerfile";           Context = "." }
)

foreach ($svc in $services) {
    if ($Target -ne "all" -and $Target -ne $svc.Name) {
        continue
    }

    $imageFullName = "$REGISTRY/$($svc.Name):$Tag"
    $imageLatestName = "$REGISTRY/$($svc.Name):latest"

    Write-Host "`n🚀 [1/2] Сборка $($svc.Name)..." -ForegroundColor Green
    docker build `
        -f $svc.Dockerfile `
        -t $imageFullName `
        -t $imageLatestName `
        $svc.Context

    if ($LASTEXITCODE -ne 0) {
        Write-Host "❌ Ошибка при сборке $($svc.Name)" -ForegroundColor Red
        exit 1
    }

    Write-Host "📤 [2/2] Пуш $imageFullName в ghcr.io..." -ForegroundColor Green
    docker push $imageFullName
    if ($Tag -ne "latest") {
        docker push $imageLatestName
    }

    if ($LASTEXITCODE -eq 0) {
        Write-Host "✅ $($svc.Name) успешно опубликован в GHCR!" -ForegroundColor Cyan
    } else {
        Write-Host "❌ Ошибка при пуше $($svc.Name). Проверьте права токена (read:packages, write:packages)." -ForegroundColor Red
    }
}

Write-Host "`n🎉 Все выбранные контейнеры обработаны!" -ForegroundColor Green
