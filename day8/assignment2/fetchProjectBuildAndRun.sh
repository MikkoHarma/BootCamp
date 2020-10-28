#!/bin/bash
#Write a bash script which pulls from your repository, 
#the first assignment from yesterday, then it should build and run it
progress=0
echo "------Make directory------"
mkdir -p BootCampClone
cd BootCampClone
echo "------clone project-------"
git clone https://github.com/MikkoHarma/BootCamp.git/ .
cd day7/assignment1/
ls
echo "------make project--------"
make
export LD_LIBRARY_PATH=.
echo "------run project---------"
./main
echo "------done----------------"