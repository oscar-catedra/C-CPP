#!/bin/bash

LOGFILE="registro_eventos.log"
echo "Generando archivo de log: $LOGFILE"

# Borrar si existe
[ -f "$LOGFILE" ] && rm "$LOGFILE"

TIPOS=("INFO" "WARNING" "ERROR" "DEBUG")

for i in {1..50}; do
    TIPO=${TIPOS[$RANDOM % 4]}
    echo "$i - $TIPO - Evento generado por el sistema $i" >> "$LOGFILE"
done

echo "Archivo $LOGFILE generado con éxito."


# REFERENCIA
# OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
# en Windows y Linux [ChatGPT conversación].
# https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


# chmod +x generador_log.sh

# ./generador_log.sh
