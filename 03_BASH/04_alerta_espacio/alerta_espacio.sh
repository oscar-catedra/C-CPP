
#!/bin/bash

# Partición a monitorear
PARTICION="/"

# Obtener porcentaje de uso
uso=$(df -h "$PARTICION" | awk 'NR==2 {print $5}' | tr -d '%')

# Evaluar y mostrar alerta
if [ "$uso" -ge 90 ]; then
    echo "⚠️  ALERTA: El uso de $PARTICION está al $uso%."
    echo "Considere liberar espacio."
else
    echo "✅ Espacio disponible suficiente en $PARTICION: $((100 - uso))% libre."
fi


# REFERENCIA
# OpenAI. (2025). Respuesta generada por ChatGPT sobre programación por lotes 
# en Windows y Linux [ChatGPT conversación].
# https://chatgpt.com/share/683354cd-e890-8013-a3a7-df827a7cf6eb


# chmod +x alerta_espacio.sh

# ./alerta_espacio.sh
