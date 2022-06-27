#!/bin/bash

SEP_P="####################"
SEP_SP="--------------------"
RES_PRE="-->"

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

function	exec_test
{
	echo "exec test"
	for i in ${1}/*.txt
	do
		echo "file name: ${i}"
		while read -r line
		do
			if [ "${line}" != "#" ]
			then
				echo "command: ${line}"
				eval ${line}
				echo "${SEP_SP}"
			fi
		done < ${i}
		echo ""
		echo "${SEP_P}"
	done
}

function	init_dir
{
	echo "initialisation of directory"
	for i in $@
	do
		echo "initialisation of the directory: ${i}"
		if [ ! -e ${i} ]
		then
			mkdir ${i}
			if [ ! -e ${i} ]
			then
				echo "${RES_PRE} error on directory creation"
			else
				echo "${RES_PRE} directory created"
			fi
		else
			echo "directory already exists"
		fi
	done
	echo "${SEP_P}"
}

function	check_dir
{
	echo "checking directory"
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
	echo "${SEP_P}"
}

function	main
{
	clear && echo "Terminal cleared"
	echo "${SEP_P}"
	if check_dir ${UC_P}; [ $? != 0 ]
	then
		exit 1
	fi
	init_dir ${RES_P}
	exec_test ${UC_P} ${RES_ORI}
	exit 0
}

main
