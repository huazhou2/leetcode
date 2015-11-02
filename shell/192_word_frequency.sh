#!/bin/bash
#count and print word frequency in text
awk '{
	for (i=1;i<=NF;i++)
		table[$i]=table[$i]+1
}
END {
	for (key in table) 
		print key" "table[key]
}' $1 |sort -rk2 -n
