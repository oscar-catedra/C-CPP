@echo off
setlocal enabledelayedexpansion

:: Crear carpeta de logs si no existe
if not exist logs (
    mkdir logs
)

:: Crear archivo de log con fecha y hora
set fecha=%date:~10,4%-%date:~4,2%-%date:~7,2%
set hora=%time:~0,2%-%time:~3,2%
set archivo=logs\log_%fecha%_%hora%.txt

:: Generar contenido del log
echo [INFO] Sistema iniciado a las %time% del %date% > %archivo%
echo [ERROR] Fallo de red detectado >> %archivo%
echo [WARN] Memoria al 80%% >> %archivo%
echo [INFO] Fin del proceso >> %archivo%

echo Log generado: %archivo%

:: Buscar la palabra "ERROR" en todos los logs
echo Analizando errores...
findstr /I "ERROR" logs\*.txt > resumen_errores.txt
echo Resultado guardado en resumen_errores.txt

:: Crear subdirectorio de respaldo con fecha
set respaldo=backup\%fecha%
mkdir %respaldo%
copy logs\*.txt %respaldo% > nul
echo Logs archivados en %respaldo%

pause


:: INDICACIONES

:: Crear carpeta de logs si no existe

:: Generar archivos de log con fecha y hora

:: Buscar palabras clave en logs

:: Guardar los resultados en otro archivo

:: Archivar automáticamente los logs en un subdirectorio con fecha

:: REFERENCIA
:: OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
:: en Windows y Linux [ChatGPT conversación].
:: https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb

