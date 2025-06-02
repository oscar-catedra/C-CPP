
#!/bin/bash

while true; do
    clear
    echo "==============================="
    echo "      MENÚ DE OPCIONES"
    echo "==============================="
    echo "1. Crear un archivo de texto"
    echo "2. Mostrar archivos del directorio actual"
    echo "3. Salir"
    echo "==============================="
    read -p "Elige una opción (1-3): " opcion

    case $opcion in
        1)
            read -p "Escribe el nombre del archivo (sin extensión): " nombre
            echo "Archivo creado con éxito" > "${nombre}.txt"
            echo "Se ha creado ${nombre}.txt"
            read -p "Presiona ENTER para continuar..."
            ;;
        2)
            echo "Archivos en el directorio actual:"
            for f in *; do
                echo "$f"
            done
            read -p "Presiona ENTER para continuar..."
            ;;
        3)
            echo "Gracias por usar el programa."
            break
            ;;
        *)
            echo "Opción no válida."
            read -p "Presiona ENTER para continuar..."
            ;;
    esac
done


# REFERENCIA
# OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
# en Windows y Linux [ChatGPT conversación].
# https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


# chmod +x menu.sh

# ./menu.sh