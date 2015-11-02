#!/bin/bash
#This script prints the 10th line of a file
filename=$1
awk 'NR==10' $filename

