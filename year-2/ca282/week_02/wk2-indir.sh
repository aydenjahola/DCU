#!/bin/sh

dir="$1"
shift
cd "$dir" || exit 1
"$@"
