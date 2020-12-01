#!/bin/bash
#Write a bash script which pulls from your repository, 
#the first assignment from yesterday, then it should build and run it
#sparse-checkout

echo "------Make directory------"
mkdir -p cd day7/assignment1/
cd cd day7/assignment1/
echo "------clone project-------"
git sparse-checkout init
git sparse-checkout set
git clone https://github.com/MikkoHarma/BootCamp.git/ .
ls
echo "------make project--------"
make
export LD_LIBRARY_PATH=.
echo "------run project---------"
./main
echo "------done----------------"