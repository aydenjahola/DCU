#!/bin/sh

for arg in "$@"; do
    if [ -e "$arg" ]; then
        if [ -d "$arg" ]; then
            echo "$arg directory"
        elif [ -f "$arg" ]; then
            echo "$arg file"
        else
            echo "$arg is of unknown type"
        fi
    else
        echo "$arg does not exist"
    fi
done
