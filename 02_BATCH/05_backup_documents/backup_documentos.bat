
@echo off
setlocal
set FECHA=%date:~10,4%-%date:~4,2%-%date:~7,2%
set HORA=%time:~0,2%-%time:~3,2%
set USERDOCS=%USERPROFILE%\Documents
set DESTINO=D:\Backup_Documentos_%FECHA%_%HORA%

echo -----------------------------------------
echo Creando respaldo de tus Documentos...
echo De: %USERDOCS%
echo A:  %DESTINO%
echo -----------------------------------------

xcopy "%USERDOCS%" "%DESTINO%" /E /I /Y > nul

echo Copia de seguridad completada.
pause

:: REFERENCIA
:: OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
:: en Windows y Linux [ChatGPT conversación].
:: https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


