#!/bin/bash

GITHUB_USER=$1


RUTA="https://api.github.com/users/${GITHUB_USER}"
fecha=$(date +%Y/%m/%d)
archivo="/tmp/$fecha/saludos.log"


# Crear el directorio si no existe
mkdir -p "/tmp/$fecha"

# crear archivo si no existe
touch $archivo


RESPONSE=$(curl -s $RUTA)

if [ $(echo $RESPONSE | jq -r '.status') = "404"  ]; then
    echo "Usuario no encontrado"
    echo "ERROR: Usuario no encontrado" >> $archivo
    exit 1
fi


ID=$(echo $RESPONSE | jq -r '.id')
CREATED_AT=$(echo $RESPONSE | jq -r '.created_at')

echo "Hola $GITHUB_USER, tu id: $ID y tu cuenta fue creada el: $CREATED_AT"

echo "Hola $GITHUB_USER, tu id: $ID y tu cuenta fue creada el: $CREATED_AT" >> $archivo