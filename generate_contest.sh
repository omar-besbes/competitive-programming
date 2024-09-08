#!/bin/bash

SUPPORTED_PLATFORMS=(
    "Codeforces"
)

gum log "Choose the platform in which you wish to generate a new contest:"
PLATFORM=$(gum choose --ordered $SUPPORTED_PLATFORMS)

case $PLATFORM in

"Codeforces")
    CONTEST_NAME=$(gum input --placeholder "Input contest name:")
    CONTEST_PATH="Codeforces/$CONTEST_NAME"
    TEMPLATE="main.cpp"

    OPTIONS=()
    for ((i = 4; i <= 16; i++)); do
        LETTER=$(printf "\\$(printf '%03o' $((65 + i - 1)))")
        OPTIONS+=("A-${LETTER} (${i} files)")
    done

    gum log "Choose the number of files to generate:"
    FILE_COUNT=$(gum choose --ordered "${OPTIONS[@]}")

    mkdir -p "$CONTEST_PATH"

    START_LETTER=$(echo "$FILE_COUNT" | cut -d '-' -f 1)
    END_LETTER=$(echo "$FILE_COUNT" | cut -d '-' -f 2 | cut -d ' ' -f 1)

    START_CODE=$(printf '%d' "'$START_LETTER")
    END_CODE=$(printf '%d' "'$END_LETTER")

    for ((code = START_CODE; code <= END_CODE; code++)); do
        FILE="${CONTEST_PATH}/$(printf "\\x$(printf '%x' $code)").cpp"
        if [ ! -f "$FILE" ]; then
            cp "$TEMPLATE" "$FILE"
            gum log "Created file: $FILE"
        fi
    done
    ;;

esac
