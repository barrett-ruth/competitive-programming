#!/bin/bash

for dir in */; do
    dir_name="${dir%/}" # Remove trailing slash
    
    for file in "$dir"*.*; do
        ext="${file##*.}"  # Extract extension
        mv "$file" "./${dir_name}.$ext"
    done

done
