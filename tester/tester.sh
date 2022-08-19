#!/bin/bash

## PROGRAM DEFINITION
BSH_NAME="bash"
SMB_NAME="minishell"

## TEST VARIABLES
ORI_P=$(pwd)
SMB_PATH=${ORI_P}/.././${SMB_NAME}
UC_P=${ORI_P}/use_case
RES_P=${ORI_P}/result
BSH_RES=${RES_P}/bsh_res
BSH_EXIT=${RES_P}/bsh_exit
SMB_RES=${RES_P}/smb_res
SMB_EXIT=${RES_P}/smb_exit
DIFF_RES=${RES_P}/diff_res
DIFF_EXIT=${RES_P}/diff_exit
BSH_STDERR=${RES_P}/bsh_stderr
SMB_STDERR=${RES_P}/smb_stderr
DIFF_STDERR=${RES_P}/diff_stderr
CMD_LIST=${RES_P}/cmd_list
COMMENT_CHAR="#"

## CONSTANT ##
SEP_P="#########################"
SEP_SP="------------------------"
CMD_PREF="==========>>>"
EXIT_LINE="TESTER EXIT STATUS: "

## COLORS ##
RD='\033[0;31m'
GN='\033[0;32m'
YE='\033[0;33m'
BU='\033[0;34m'
MG='\033[0;35m'
NC='\033[0m'

## SAVE EXPRESION
# replace new line command charset '$>' by a new line
# sed -i -e 's/$> /\n/g' xxx.txt
# OR (to be tested)
# sed -i -e 's/[^0-9]$> /\n/g' xxx.txt
#
#
# replace every '\n' by new line with echo return status
# cat xxx.txt | awk -F'\n' '{ print $1 "\necho \"TESTER EXIT STATUS: \" $?" $2 }' >xxx_OK.txt

function	create_command_list
{
	echo -e "${YE}Executing \"${FUNCNAME}: ${1}\"${NC}";
	for i in ${2}/*.txt
	do
		if [ ! -z ${3} ] && [ ${i} != ${2}/${3}.txt ]
		then
			continue;
		fi
		grep -v -iE 'TESTER EXIT STATUS: ' ${i} | cat -n > ${4};
	done
	echo -e "${YE}${SEP_P}${NC}";
}

function	diff_exit_status
{
	local sed_seq="";

	echo -e "${YE}Executing \"${FUNCNAME}: ${1}\"${NC}";
	#diff --suppress-common-lines -y ${3} ${2} > ${4}
	diff -y ${3} ${2} > ${4}
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	check_exit_status
{
	echo -e "${YE}Executing \"${FUNCNAME}: ${1}\"${NC}";
	#grep -B 2 -iE 'TESTER EXIT STATUS: ' ${2} | awk '{ print $4 }' > ${3}
	#grep -B 1 -iE 'TESTER EXIT STATUS: ' ${2} | awk 'NR%2 !=0 { print $0 } ; NR%2 == 0 { print $4 };' > ${3}
	grep -iE '^TESTER EXIT STATUS: ' ${2} | awk 'BEGIN{i=1} { printf "command %d: %s\n",i, $4; i+=1 };' > ${3};
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	diff_full
{
	local sed_seq="";

	echo -e "${YE}Executing \"${FUNCNAME}: ${1}\"${NC}";
	#diff -y ${2} ${3} > ${4} && echo "Diff file \"${4}\" has been created" || echo "Error: impossible to create the diff file \"${4}\"";
	#if [ "$?" != 0 ]; then return 1; fi;
	diff -y ${3} ${2} > ${4}
	sed -i 's/^.*\$: /\n\n\n\n\n-------------------------------------------------------------------------------------\n==========>>> /g' ${4};
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	test_full
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
		#${4} < ${i} >> ${5};
		#echo "${SEP_P}" >> ${5} 2>>${6};
		echo "${SEP_P}" >> ${5} 2>>${5};
		#echo "${SEP_P}" >> ${5};
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

function	minishell_path
{
	local usr_path="${1}"
	local usr_answer=""

	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	while [ "${usr_answer}" != "y" ] && [ "${usr_answer}" != "n" ]
	do
		echo "Actual minishell path: ${usr_path}";
		read -n 200 -p "What is the relative minishell program path ? " usr_path;
		echo "Answer: ${usr_path}";
		if check_file ${usr_path}; [ $? != 0 ]
		then
			read -n 1 -p "Do you want to retry [y/n] ? " usr_answer;
			echo "";
			echo "Answer: ${usr_answer}";
			if [ "${usr_answer}" == "y" ]
			then
				usr_answer="z";
				usr_path="${1}";
			fi
		else
			while [ "${usr_answer}" != "y" ] && [ "${usr_answer}" != "n" ]
			do
				read -n 1 -p "Do you want to continue [y/n] ? " usr_answer;
				echo "";
				echo "Answer: ${usr_answer}";
			done
		fi
	done
	if [ "${usr_answer}" == "n" ]
	then
		echo -e "${BU}The process has been stopped${NC}";
		return 3;
	fi
	if [ "$?" != 0 ]; then return 3; fi;
	echo -e "${YE}${SEP_P}${NC}";

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
		rm -rf ${2} && echo -e "${BU}Directory \"${2}\" has been deleted from the current directory \"${1}\"${NC}" || echo -e "${RD}Error: impossible to delete the directory \"${2}\" from the current directory \"${1}\"${NC}";
		if [ "$?" != 0 ]; then return 2; fi;
	else
		echo -e "${BU}The process has been stopped${NC}";
		return 3;
	fi
	mkdir ${2} && echo -e "${GN}Directory \"${2}\" has been created in the current directory \"${1}\"${NC}" || echo -e "${RD}Error: impossible to create the directory \"${2}\" in the current directory \"${1}\"${NC}";
	if [ "$?" != 0 ]; then return 3; fi;
	echo -e "${YE}${SEP_P}${NC}";
}

function	check_file
{
#	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	echo "check file on string: ${i}";
	if [ -z ${1} ]
	then
		echo -e "${RD}file ${i} not existing${NC}";
		return 1;
	else
		echo -e "${GN}file ${i} existing${NC}";
	fi
#	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	check_dir_res
{
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	for i in $@
	do
		if [ ! -e ${i} ]
		then
			echo -e "${RD}directory ${i} not existing${NC}";
			return 1;
		else
			echo -e "${GN}directory ${i} existing${NC}";
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
			echo -e "${RD}directory ${i} not existing${NC}";
			return 1;
		else
			echo -e "${GN}directory ${i} existing${NC}";
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
#	minishell_path ${SMB_PATH};
#	if [ "$?" != 0 ]; then return 3; fi;
	create_command_list "CMD" ${UC_P} ${1} ${CMD_LIST};
	test_full "BASH" ${UC_P} ${1} ${BSH_NAME} ${BSH_RES} ${BSH_STDERR};
	test_full "SMB" ${UC_P} ${1} ${SMB_PATH} ${SMB_RES} ${SMB_STDERR};
	diff_full "RES" ${BSH_RES} ${SMB_RES} ${DIFF_RES};
	#diff_full "STDERR" ${BSH_STDERR} ${SMB_STDERR} ${DIFF_STDERR};
 	check_exit_status "BASH" ${BSH_RES} ${BSH_EXIT};
	check_exit_status "SMB" ${SMB_RES} ${SMB_EXIT};
	diff_exit_status "EXIT" ${BSH_EXIT} ${SMB_EXIT} ${DIFF_EXIT};
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
