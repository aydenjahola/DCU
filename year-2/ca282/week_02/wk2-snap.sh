#!/bin/sh

awk 'a==$0 {print $0; exit} {a=$0}' -
