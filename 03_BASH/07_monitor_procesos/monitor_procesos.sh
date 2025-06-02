#!/bin/bash

echo "---------------------------------------------"
echo "     MONITOREO DE PROCESOS EN LINUX"
echo "---------------------------------------------"

fecha=$(date +"%Y-%m-%d_%H-%M-%S")
archivo="procesos_top_$fecha.txt"

# Mostrar los 10 procesos que más CPU consumen
echo "Top 10 procesos por uso de CPU:"
ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%cpu | head -n 11 | tee "$archivo"

echo
echo "Información guardada en: $archivo"

# Puedes programarlo en cron para ejecutarlo cada cierto tiempo


# REFERENCIA
# OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
# en Windows y Linux [ChatGPT conversación].
# https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


# chmod +x monitor_procesos.sh

# ./monitor_procesos.sh
