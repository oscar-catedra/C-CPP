@echo off
setlocal

echo ================================================
echo   LIMPIEZA DE ARCHIVOS TEMPORALES EN WINDOWS
echo ================================================
echo.

REM Mostrar rutas de carpetas temporales
echo Carpeta temporal del sistema: %windir%\Temp
echo Carpeta temporal del usuario: %TEMP%
echo.

REM Mostrar cuántos archivos hay antes
echo Archivos en carpeta temporal del sistema:
dir /a /b %windir%\Temp | find /v /c "" 


echo Archivos en carpeta temporal del usuario:
dir /a /b %TEMP% | find /v /c "" 

REM Limpiar temporales del sistema
echo.
echo Eliminando archivos temporales del sistema...
del /s /f /q %windir%\Temp\*.* >nul 2>&1
echo Listo.

REM Limpiar temporales del usuario
echo Eliminando archivos temporales del usuario...
del /s /f /q %TEMP%\*.* >nul 2>&1
echo Listo.

REM Espacio en disco
echo.
echo Espacio en disco:
wmic logicaldisk get Caption,FreeSpace,Size

echo.
echo Limpieza completada.
pause



:: DESCRIPCIÓN

:: Eliminar archivos temporales del sistema y del usuario. 
:: Ideal para enseñar cómo automatizar mantenimiento básico del sistema.
:: Usa wmic para mostrar el espacio libre en cada unidad al final del proceso.

:: REFERENCIA
:: OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
:: en Windows y Linux [ChatGPT conversación].
:: https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb
