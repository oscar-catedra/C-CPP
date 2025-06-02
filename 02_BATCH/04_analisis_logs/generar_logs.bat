@echo off
setlocal enabledelayedexpansion

set LOGFILE=registro_eventos.log
echo Generando archivo de log: %LOGFILE%
echo.

REM Borrar si ya existe
if exist %LOGFILE% del %LOGFILE%

REM Simular 50 líneas de eventos
for /L %%i in (1,1,50) do (
    set /A RND=%RANDOM%%%4
    if !RND!==0 (set TIPO=INFO)
    if !RND!==1 (set TIPO=WARNING)
    if !RND!==2 (set TIPO=ERROR)
    if !RND!==3 (set TIPO=DEBUG)

    echo %%i - !TIPO! - Evento generado por el sistema %%i >> %LOGFILE%
)

echo Archivo %LOGFILE% generado con éxito.
pause


:: REFERENCIA
:: OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
:: en Windows y Linux [ChatGPT conversación].
:: https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


