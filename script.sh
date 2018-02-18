#!/bin/bash

filename="$1"
while read -r line
do
	i=1
	for row in $(./dnslookup "$line" | cut -d ' ' -f 2,3)
	do
		mod=$(( $i % 2 ))
		if [ $mod -eq 1 ]; then
			IPversion=$row
		else
			if [ "$IPversion" == "IPv4" ]; then
				traceroute -4 -q 1 -n $row >> IPv4.txt
				echo "\n" >> IPv4.txt
				echo $line
				echo traceroute -4 -q 1 -n $row
			else
				traceroute -6 -q 1 -n $row >> IPv6.txt
				echo "\n" >> IPv6.txt
				echo $line
				echo traceroute -6 -q 1 -n $row
			fi
		fi
		
	let "i++"
	done
done < "$filename"
