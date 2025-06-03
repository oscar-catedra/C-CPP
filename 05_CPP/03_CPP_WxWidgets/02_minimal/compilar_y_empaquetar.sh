#!/usr/bin/env bash

# 🧾 Verificación de argumentos
if [ -z "$1" ]; then
    echo "❌ Uso: $0 archivo_fuente.cpp"
    exit 1
fi

CPP_FILE="$1"
BASENAME=$(basename "$CPP_FILE" .cpp)
EXE="$BASENAME.exe"
OUT_DIR="$BASENAME"

echo "🛠 Compilando $CPP_FILE..."
g++ "$CPP_FILE" -o "$EXE" $(wx-config --cxxflags --libs)
if [ $? -ne 0 ]; then
    echo "❌ Error en la compilación"
    exit 1
fi

echo "📦 Preparando carpeta '$OUT_DIR/'..."
mkdir -p "$OUT_DIR"
cp "$EXE" "$OUT_DIR/"

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

echo "🗜 Empaquetando en '$OUT_DIR.zip'..."
zip -r "$OUT_DIR.zip" "$OUT_DIR" > /dev/null

echo "✅ Listo: ejecutable y DLLs empaquetados en '$OUT_DIR/' y '$OUT_DIR.zip'"

# REFERENCIA
# OpenAI. (2025). Script Bash para compilar y empaquetar 
# aplicaciones wxWidgets con MSYS2-UCRT64 en Windows 
# [Asistente conversacional, ChatGPT]. 
#  https://chat.openai.com/

# chmod +x compilar_y_empaquetar.sh
# ./compilar_y_empaquetar.sh mi_programa.cpp



