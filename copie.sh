#!/usr/bin/env bash

set -euo pipefail

# Racine du projet
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
OUTPUT="$ROOT/source.txt"

cd "$ROOT"

echo "========================================"
echo "  GENERATION DU FICHIER SOURCE.TXT"
echo "========================================"

# Vérifier les outils nécessaires
if ! command -v find >/dev/null 2>&1; then
    echo "Erreur : find n'est pas installé."
    exit 1
fi

# Créer ou vider le fichier de sortie
: > "$OUTPUT"

# 1. Générer l'arborescence du projet
{
    echo "========================================"
    echo "ARBORESCENCE DU PROJET"
    echo "========================================"
    echo

    find . \
        \( -type d \( \
            -name build -o \
            -name .git -o \
            -name .idea -o \
            -name .vscode -o \
            -name node_modules \
        \) -prune \) -o \
        \( -type f \
            ! -name source.txt \
            ! -name copie.sh \
            -print \
        \) |
        sort

    echo
    echo "========================================"
    echo "CONTENU DES FICHIERS"
    echo "========================================"
    echo
} >> "$OUTPUT"

# 2. Ajouter le contenu des fichiers texte
while IFS= read -r -d '' file; do

    relative="${file#./}"

    # Exclure les fichiers susceptibles de contenir des secrets
    case "$relative" in
        .env|.env.*|*/.env|*/.env.*|\
        *.pem|*.key|*.p12|*.pfx|\
        *credentials*|*secret*|*password*)
            echo "Exclusion sensible : $relative"
            continue
            ;;
        config/application.properties|\
        */config/application.properties)
            echo "Configuration exclue : $relative"
            continue
            ;;
    esac

    # Ignorer les fichiers binaires
    if ! grep -Iq . "$file"; then
        echo "Fichier binaire ignoré : $relative"
        continue
    fi

    {
        echo
        echo "##################################################"
        echo "FICHIER : $relative"
        echo "##################################################"
        echo

        cat -- "$file"

        echo
        echo
    } >> "$OUTPUT"

done < <(
    find . \
        \( -type d \( \
            -name build -o \
            -name .git -o \
            -name .idea -o \
            -name .vscode -o \
            -name node_modules \
        \) -prune \) -o \
        \( -type f \
            ! -name source.txt \
            ! -name copie.sh \
            -print0 \
        \)
)

echo
echo "========================================"
echo "Generation terminee !"
echo "========================================"
echo "Fichier cree : $OUTPUT"
echo
ls -lh "$OUTPUT"