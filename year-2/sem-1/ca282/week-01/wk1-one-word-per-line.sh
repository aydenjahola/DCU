#!/bin/sh

while IFS= read -r line; do
  echo "$line" | awk '{ for(i=1; i<=NF; i++) print $i }'
done
