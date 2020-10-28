#!/bin/bash
#Write abash script which takes as input an URL, downloads the
#file, changes all instances of “Volvo” to “The Best Company Ever” .
# Hint : Look into wget and sed

# https://sv.wikipedia.org/wiki/Volvo

wget $1 -O output.html
sed "s/Volvo/The Best Company Ever/ig" output.html > output_transformed.html
firefox --new-instance -url ${0%/*}/output_transformed.html

#file:///home/mikko/work/SWBootCamp/day8/bonus1/output_transformed.html