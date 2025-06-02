#!/bin/bash

while true; do
    clear
    echo "==============================="
    echo "     UTILIDADES EN BASH"
    echo "==============================="
    echo "1. Crear un archivo de texto"
    echo "2. Leer contenido de un archivo"
    echo "3. Contar líneas de un archivo"
    echo "4. Eliminar un archivo"
    echo "5. Salir"
    echo "==============================="
    read -p "Elige una opción (1-5): " opcion

    case $opcion in
        1)
            read -p "Nombre del archivo (sin extensión): " nombre
            echo "Este es un archivo de ejemplo" > "${nombre}.txt"
            echo "Se creó el archivo ${nombre}.txt"
            read -p "Presiona ENTER para continuar..."
            ;;
        2)
            read -p "Nombre del archivo a leer (con extensión): " archivo
            if [[ -f "$archivo" ]]; then
                cat "$archivo"
            else
                echo "El archivo no existe."
            fi
            read -p "Presiona ENTER para continuar..."
            ;;
        3)
            read -p "Nombre del archivo a contar líneas (con extensión): " archivo
            if [[ -f "$archivo" ]]; then
                lineas=$(wc -l < "$archivo")
                echo "El archivo tiene $lineas líneas."
            else
                echo "El archivo no existe."
            fi
            read -p "Presiona ENTER para continuar..."
            ;;
        4)
            read -p "Nombre del archivo a eliminar (con extensión): " archivo
            if [[ -f "$archivo" ]]; then
                rm "$archivo"
                echo "Archivo eliminado."
            else
                echo "El archivo no existe."
            fi
            read -p "Presiona ENTER para continuar..."
            ;;
        5)
            echo "Gracias por usar el programa."
            break
            ;;
        *)
            echo "Opción inválida."
            read -p "Presiona ENTER para continuar..."
            ;;
    esac
done

# REFERENCIA
# OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
# en Windows y Linux [ChatGPT conversación].
# https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


# chmod +x utilidades.sh

# ./utilidades.sh