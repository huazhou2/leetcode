#!/bin/bash
#Transpose a file
awk '{
	for (i=1;i<=NF;i++) 
		mat[NR,i]=$i
	}
END {
	for (i=1;i<=NF;i++) {
	 	str=mat[1,i]
		for (j=2;j<=NR;j++) 
			str=str" "mat[j,i]
		print str
	}
}' $1
