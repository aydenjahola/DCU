#!/bin/sh

reg_files=true

for arg in "$@"; do
    test -f "$arg" || reg_files=false
done

$reg_files
