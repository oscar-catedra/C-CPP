#!/usr/bin/env bash

# Verificar argumento
if [ -z "$1" ]; then
    echo "❌ Uso: $0 nombre_programa.exe"
    exit 1
fi

EXE="$1"
BASENAME=$(basename "$EXE" .exe)
OUT_DIR="$BASENAME"

# Crear carpeta primero, como tú indicas
echo "📦 Preparando carpeta '$OUT_DIR/'..."
mkdir -p "$OUT_DIR"

# Verificar si el ejecutable existe
if [ ! -f "$EXE" ]; then
    echo "❌ Error: no se encontró el archivo '$EXE'"
    exit 1
fi

# Copiar el ejecutable
cp "$EXE" "$OUT_DIR/"

# Usar ldd para encontrar las DLL requeridas
echo "🔍 Buscando dependencias con ldd..."
ldd "$EXE" | grep '=> /ucrt64/bin/' | awk '{print $3}' > dlls.txt

echo "📄 Copiando DLLs necesarias a '$OUT_DIR/'..."
while read dll; do
    if [ -f "$dll" ]; then
        echo "➤ $(basename "$dll")"
        cp "$dll" "$OUT_DIR/"
    fi
done < dlls.txt

rm dlls.txt

echo "✅ Listo: carpeta '$OUT_DIR/' con ejecutable y DLLs empaquetadas."

# REFERENCIAS

# OpenAI. (2025). Script Bash para compilar y empaquetar aplicaciones 
# wxWidgets con MSYS2-UCRT64 en Windows 
# [Asistente conversacional, ChatGPT]. https://chat.openai.com/

# chmod +x empaqueta_dependencias.sh
#
# ./empaqueta_dependencias.sh mi_programa.exe


