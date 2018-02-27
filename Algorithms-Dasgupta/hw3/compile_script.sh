#!/usr/bin/env bash

for i in *.cpp
do
    #uncomment echo for testing purposes
    #echo "g++ -S -o "$i" "${i%.cpp}.s"" 
    g++ -S -o "${i%.cpp}.s" "$i"
done