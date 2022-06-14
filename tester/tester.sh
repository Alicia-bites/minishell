#!/bin/bash

SEP_P="####################"
SEP_SP="--------------------"

BK_RD='\033[31;7m'
BK_GN='\033[32;7m'
BK_YE='\033[33;7m'
RD='\033[0;31m'
GN='\033[0;32m'
YE='\033[0;33m'
BU='\033[0;34m'
MG='\033[0;35m'
NC='\033[0m'

ORI_P=$(pwd)
UC_P=${ORI_P}/use_case
RES_P=${ORI_P}/result
RES_ORI=${RES_P}/result_ori

#while read -r line
#do
#  echo "$line"
#done < "$input"

function	init_all_files
{
	for i in $@
	do
		echo ${i}
#		if [ ]
#		then
#		fi
	done
}

function	check_dir
{
	for i in $@
	do
		if [ ! -e ${i} ]
		then
			echo "directory ${i} not existing"
			exit 1
		else
			echo "directory ${i} existing"
		fi
	done
}

function	main
{
	clear && echo "Terminal cleared"
	if check_dir ${UC_P}; [ $? != 0 ]
	then
		exit 1
	fi
	#init_all_files ${RES_P} ${RES_ORI}
	exit 0
}

main
