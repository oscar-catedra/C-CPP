
#!/bin/bash

echo "=============================================="
echo "    LIMPIEZA DE ARCHIVOS TEMPORALES EN LINUX"
echo "=============================================="

# Rutas comunes de archivos temporales
TEMP_USER="/tmp"
CACHE_USER="$HOME/.cache"
TRASH="$HOME/.local/share/Trash/files"

echo
echo "📂 Directorios a limpiar:"
echo "1. $TEMP_USER"
echo "2. $CACHE_USER"
echo "3. $TRASH"
echo

# Espacio antes de limpiar
echo "💾 Espacio en disco antes de limpiar:"
df -h /

# Contar archivos antes
count_files() {
  local dir="$1"
  echo -n "→ Archivos en $dir: "
  find "$dir" -type f 2>/dev/null | wc -l
}

echo
count_files "$TEMP_USER"
count_files "$CACHE_USER"
count_files "$TRASH"

# Borrar archivos (solo archivos, no directorios base)
echo
echo "🧹 Limpiando archivos temporales..."

delete_files() {
  local dir="$1"
  echo "→ Limpiando $dir..."
  find "$dir" -type f -exec rm -f {} + 2>/dev/null
}

delete_files "$TEMP_USER"
delete_files "$CACHE_USER"
delete_files "$TRASH"

# Contar archivos después
echo
echo "📦 Archivos restantes después de la limpieza:"
count_files "$TEMP_USER"
count_files "$CACHE_USER"
count_files "$TRASH"

# Espacio después de limpiar
echo
echo "💾 Espacio en disco después de limpiar:"
df -h /

echo
echo "✅ Limpieza completada."


# REFERENCIA
# OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
# en Windows y Linux [ChatGPT conversación].
# https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


# chmod +x limpia_temporales.sh

# ./limpia_temporales.sh
