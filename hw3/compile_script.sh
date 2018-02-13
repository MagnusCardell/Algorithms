#!/usr/bin/env bash

for i in *.cpp
do
    echo "g++ -S -o "$i" "${i%.cpp}.s""
    g++ -S -o "$i" "${i%.cpp}.s"
done