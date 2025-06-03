
#!/usr/bin/env bash

if [ $# -ne 1 ]; then
  echo "Uso: $0 <archivo_con_o_sin_extension_c_cpp_cc>"
  echo "Ejemplos:"
  echo "  $0 hola_mundo_raylib"
  echo "  $0 hola_mundo_raylib.c"
  echo "  $0 hola_mundo_raylib.cpp"
  echo "  $0 hola_mundo_raylib.cc"
  exit 1
fi

INPUT="$1"

# Extraer nombre base y extensión
BASENAME=$(basename "$INPUT" | sed 's/\.[^.]*$//')  # Quita extensión si existe
EXTENSION="${INPUT##*.}"

# Función para detectar si es extensión válida
is_valid_extension() {
  case "$1" in
    c|cpp|cc) return 0 ;;
    *) return 1 ;;
  esac
}

if is_valid_extension "$EXTENSION"; then
  SRC_FILE="$BASENAME.$EXTENSION"
else
  # Si no tiene extensión válida, probar .c, .cpp, .cc en ese orden
  if [ -f "$BASENAME.c" ]; then
    SRC_FILE="$BASENAME.c"
    EXTENSION="c"
  elif [ -f "$BASENAME.cpp" ]; then
    SRC_FILE="$BASENAME.cpp"
    EXTENSION="cpp"
  elif [ -f "$BASENAME.cc" ]; then
    SRC_FILE="$BASENAME.cc"
    EXTENSION="cc"
  else
    echo "Error: No se encontró $BASENAME.c, $BASENAME.cpp ni $BASENAME.cc"
    exit 1
  fi
fi

# Elegir compilador según extensión
COMPILER=""
if [ "$EXTENSION" == "c" ]; then
  COMPILER="gcc"
elif [ "$EXTENSION" == "cpp" ] || [ "$EXTENSION" == "cc" ]; then
  COMPILER="g++"
else
  echo "Error: extensión desconocida $EXTENSION"
  exit 1
fi

EXE_NAME="$BASENAME.exe"
DIST_DIR="$BASENAME"

echo "Compilando $SRC_FILE con $COMPILER..."
$COMPILER "$SRC_FILE" -o "$EXE_NAME" -lraylib -lwinmm -lgdi32

if [ $? -ne 0 ]; then
  echo "❌ Error en compilación"
  exit 1
fi

echo "Creando directorio de distribución: $DIST_DIR"
mkdir -p "$DIST_DIR"

echo "Copiando ejecutable a $DIST_DIR"
cp "$EXE_NAME" "$DIST_DIR/"

echo "Obteniendo lista de dependencias DLL con ldd..."
DLLS=$(ldd "$EXE_NAME" | grep "=> /" | awk '{print $3}' | sort -u)

echo "Copiando DLLs necesarias a $DIST_DIR"
for dll in $DLLS; do
  cp "$dll" "$DIST_DIR/"
done

# Crear zip
ZIP_NAME="${BASENAME}_package.zip"
echo "Creando archivo comprimido $ZIP_NAME..."
zip -r "$ZIP_NAME" "$DIST_DIR"

echo "✅ Empaquetado listo en $ZIP_NAME"
echo "👉 Extrae y ejecuta $EXE_NAME desde la carpeta $DIST_DIR"



# Referencia
# OpenAI. (2025, mayo 24). Compilar y distribuir programas de Raylib en Windows 
# usando MSYS2 UCRT64 [ChatGPT]. ChatGPT. 
# https://chatgpt.com/share/6831f399-7888-8013-91da-24df84e0d612

# chmod +x build_and_package.sh

# ./build_and_package.sh archivo.c
# ./build_and_package.sh archivo.cc
#  ./build_and_package.sh archivo.cpp
#  ./build_and_package.sh archivo