# Definir a cor desejada
$ForegroundColor = "Green"

# Caminho para o perfil
$ProfilePath = $PROFILE

# Linha que será adicionada no perfil (usando acento grave ` para escapar o $ corretamente)
$ColorLine = "`$Host.UI.RawUI.ForegroundColor = `"$ForegroundColor`"`n"

# Verificar se o perfil existe, se não, cria
if (-not (Test-Path $ProfilePath)) {
    New-Item -ItemType File -Path $ProfilePath -Force | Out-Null
}

# Verificar se a configuração já está no perfil
if (-not (Select-String -Path $ProfilePath -Pattern '\$Host\.UI\.RawUI\.ForegroundColor')) {
    Add-Content -Path $ProfilePath -Value "`n# Cor personalizada adicionada automaticamente`n$ColorLine"
    Write-Host "Cor '$ForegroundColor' adicionada ao perfil com sucesso." -ForegroundColor Green
}
else {
    Write-Host "Cor já configurada no perfil." -ForegroundColor Yellow
}

Write-Host "Reabra o PowerShell para ver a cor '$ForegroundColor' aplicada!" -ForegroundColor Cyan
