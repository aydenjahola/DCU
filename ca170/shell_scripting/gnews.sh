#!/bin/bash

# Check if an argument is passed to the script
if [ $# -eq 0 ]; then
  echo "Please provide an argument"
  exit 1
fi

# Get today's news from RTE using wget
wget -qO- "https://www.rte.ie/news/" |

# Search the page for the argument using grep
grep "$1" |

# Print the result
# The sed command removes any HTML tags from the output
sed 's/<[^>]*>//g'
