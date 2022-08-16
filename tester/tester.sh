#!/bin/bash

## PROGRAM DEFINITION
BSH_NAME="bash"
SMB_NAME="minishell"

## TEST VARIABLES
ORI_P=$(pwd)
UC_P=${ORI_P}/use_case
RES_P=${ORI_P}/result
BSH_RES=${RES_P}/bsh_res
SMB_RES=${RES_P}/smb_res
DIFF_RES=${RES_P}/diff_res
BSH_STDERR=${RES_P}/bsh_stderr
SMB_STDERR=${RES_P}/smb_stderr
DIFF_STDERR=${RES_P}/diff_stderr
COMMENT_CHAR="#"

## CONSTANT ##
SEP_P="#########################"
SEP_SP="------------------------"
CMD_PREF="----->"

## COLORS ##
RD='\033[0;31m'
GN='\033[0;32m'
YE='\033[0;33m'
BU='\033[0;34m'
MG='\033[0;35m'
NC='\033[0m'

function	exec_diff
{
	local sed_seq="";

	echo -e "${YE}Executing \"${FUNCNAME}: ${1}\"${NC}";
	#diff -y ${2} ${3} > ${4} && echo "Diff file \"${4}\" has been created" || echo "Error: impossible to create the diff file \"${4}\"";
	#if [ "$?" != 0 ]; then return 1; fi;
	diff -y ${3} ${2} > ${4}
	sed -i 's/^.*\$: /==========>>> /g' ${4};
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	exec_redir_test
{
	echo -e "${YE}Executing \"${FUNCNAME}: ${1}\"${NC}";
	for i in ${2}/*.txt
	do
		if [ ! -z ${3} ] && [ ${i} != ${2}/${3}.txt ]
		then
			continue;
		fi
		#echo -e "${VT}file name: ${i}${NC}" >> ${5} 2>>${6};
		echo -e "${VT}file name: ${i}${NC}" >> ${5} 2>>${5};
		#${4} < ${i} >> ${5} 2>>${6};
		${4} < ${i} >> ${5} 2>>${5};
		#echo "${SEP_P}" >> ${5} 2>>${6};
		echo "${SEP_P}" >> ${5} 2>>${5};
	done
	echo -e "${YE}${SEP_P}${NC}";
}

function	init_dir
{
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	for i in $@
	do
		echo "initialisation of the directory: ${i}";
		if [ ! -e ${i} ]
		then
			mkdir ${i} && echo "Directory \"${i}\" has been created" || echo "Error: impossible to create the directory \"${i}\"";
			if [ "$?" != 0 ]; then return 1; fi;
		else
			echo "directory already exists";
		fi
	done
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	create_dir_res
{
	local usr_answer=""

	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	while [ "${usr_answer}" != "y" ] && [ "${usr_answer}" != "n" ]
	do
		read -n 1 -p "The process will delete the directory. Do you want to continue [y/n] ? " usr_answer;
		echo "";
		echo "Answer: ${usr_answer}";
	done
	if [ "${usr_answer}" == "y" ]
	then
		rm -rf ${2} && echo "Directory \"${2}\" has been deleted from the current directory \"${1}\"" || echo "Error: impossible to delete the directory \"${2}\" from the current directory \"${1}\"";
		if [ "$?" != 0 ]; then return 2; fi;
	else
		echo -e "${BU}The process has been stopped${NC}";
		return 3;
	fi
	mkdir ${2} && echo "Directory \"${2}\" has been created in the current directory \"${1}\"" || echo "Error: impossible to create the directory \"${2}\" in the current directory \"${1}\"";
	if [ "$?" != 0 ]; then return 3; fi;
	echo -e "${YE}${SEP_P}${NC}";
}

function	check_dir_res
{
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	for i in $@
	do
		if [ ! -e ${i} ]
		then
			echo "directory ${i} not existing";
			return 1;
		else
			echo "directory ${i} existing";
		fi
	done
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}


function	check_dir_uc
{
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	for i in $@
	do
		if [ ! -e ${i} ];
		then
			echo "directory ${i} not existing";
			return 1;
		else
			echo "directory ${i} existing";
		fi
	done
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	main
{
	echo -e "${YE}${SEP_P}${NC}";
	if check_dir_uc ${UC_P}; [ $? != 0 ]
	then
		return 1;
	fi
	check_dir_res ${RES_P};
	create_dir_res ${ORI_P} ${RES_P};
	if [ "$?" != 0 ]; then return 2; fi;
	exec_redir_test "BASH" ${UC_P} ${1} ${BSH_NAME} ${BSH_RES} ${BSH_STDERR};
	exec_redir_test "SMB" ${UC_P} ${1} ${ORI_P}/.././${SMB_NAME} ${SMB_RES} ${SMB_STDERR};
	exec_diff "RES" ${BSH_RES} ${SMB_RES} ${DIFF_RES};
	#exec_diff "STDERR" ${BSH_STDERR} ${SMB_STDERR} ${DIFF_STDERR};
	return 0;
}

clear;
echo "Program${0} - Start";
main ${1}
echo "Program ${0} - End";
exit $?

## DEPRICATED FUNCTIONS
#function	exec_test
#{
#	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
#	for i in ${1}/*.txt
#	do
#		if [ ! -z ${3} ] && [ ${i} != ${1}/${3}.txt ]
#		then
#			continue
#		fi
#		echo "file name: ${i}"
#		while read -r line
#		do
#			if [[ "${line}" =~ ^#.* ]];
#			then
#				echo -e "${MG}${line}${NC}"
#			else
#				echo "command: ${line}"
#				eval ${line}
#				echo "${SEP_SP}"
#			fi
#		done < ${i}
#		echo ""
#		echo "${SEP_P}"
#	done
#}
