#!/usr/bin/env bash

TAGS=` echo $* | tr ' ' ',' `


url="https://api.flickr.com/services/feeds/photos_public.gne?format=json&tags=$TAGS"

wget -q -O - $url | egrep '"description":|"tags":' | tr -d '\\' | sed "s|<*>|<hr style='margin-top:50'><*>|" > flickr2.html
