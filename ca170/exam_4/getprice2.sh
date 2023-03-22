#!/usr/bin/env bash

# Construct the URL based on the command-line arguments
symbol=$1
day=$2
month=$3
year=$4
url="https://bigcharts.marketwatch.com/historical/default.asp?symb=$symbol&closeDate=$month%2F$day%2F$year"

# Fetch the URL using wget and store the output in a variable
output=$(wget -q -O - "$url")

# Remove Windows end of line characters and put the entire output on a single line
output=$(echo "$output" | tr -d '\r' | tr -d '\n')

# Extract the stock price using sed
price=$(echo "$output" | sed -e 's/.*Closing Price:<\/th>\s*<td>\([0-9,.]*\)<\/td>.*/\1/')

# Print the stock price
echo "$price"
