
#!/bin/bash

# Crear carpeta de logs si no existe
mkdir -p logs

# Obtener fecha y hora
fecha=$(date +"%Y-%m-%d_%H-%M-%S")
archivo="logs/log_${fecha}.log"

# Generar contenido del log
echo "[INFO] Sistema iniciado a $(date)" > "$archivo"
echo "[ERROR] No se pudo conectar a la base de datos" >> "$archivo"
echo "[WARN] Uso de CPU al 90%" >> "$archivo"
echo "[INFO] Finalizando servicio" >> "$archivo"

echo "Log generado: $archivo"

# Buscar errores en todos los logs
grep -i "ERROR" logs/*.log > resumen_errores.txt
echo "Errores encontrados y guardados en resumen_errores.txt"

# Crear carpeta de respaldo y comprimir los logs
respaldo="backup_$(date +%Y-%m-%d)"
mkdir -p "$respaldo"
cp logs/*.log "$respaldo"

# Comprimir
tar -czf "${respaldo}.tar.gz" "$respaldo"
echo "Logs archivados y comprimidos en ${respaldo}.tar.gz"

# Limpieza opcional
# rm -r "$respaldo"
# echo "Directorio temporal eliminado."

read -p "Presiona ENTER para finalizar..."

# REFERENCIA
# OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
# en Windows y Linux [ChatGPT conversación].
# https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


# chmod +x gestion_logs.sh

# ./gestion_logs.sh