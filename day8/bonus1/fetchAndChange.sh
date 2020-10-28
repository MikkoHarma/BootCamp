#!/bin/bash
#Write abash script which takes as input an URL, downloads the
#file, changes all instances of “Volvo” to “The Best Company Ever” .
# Hint : Look into wget and sed

# tested with https://sv.wikipedia.org/wiki/Volvo

#get page from argument store to file
wget $1 -O output.html

#Replace Volvo with the bes.. i=case insensitive g=global
sed "s/Volvo/The Best Company Ever/ig" output.html > output_transformed.html

#open file in browser if installed
firefox --new-instance -url ${0%/*}/output_transformed.html