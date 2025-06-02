@echo off
:menu
cls
echo ===============================
echo      MENU DE OPCIONES
echo ===============================
echo 1. Crear un archivo de texto
echo 2. Mostrar archivos del directorio actual
echo 3. Salir
echo ===============================
set /p opcion=Elige una opcion (1-3): 

if "%opcion%"=="1" goto crear_archivo
if "%opcion%"=="2" goto mostrar_archivos
if "%opcion%"=="3" goto salir
goto menu

:crear_archivo
set /p nombre=Escribe el nombre del archivo (sin extension): 
echo Archivo creado con éxito > %nombre%.txt
echo Se ha creado %nombre%.txt
pause
goto menu

:mostrar_archivos
echo Archivos en el directorio actual:
for %%f in (*.*) do (
    echo %%f
)
pause
goto menu

:salir
echo Gracias por usar el programa.
pause
exit


:: REFERENCIA
:: OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
:: en Windows y Linux [ChatGPT conversación].
:: https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb
