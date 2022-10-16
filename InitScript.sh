#!/bin/sh
CUR_DIR=$(pwd)
DIR_NAME=$1
DIR_PATH=$2
echo $DIR_NAME
echo $DIR_PATH
FINAL_PATH="${DIR_PATH}/${DIR_NAME}"
FILE_NAME="${FINAL_PATH}/init.txt"
FILE_VALUE="This is the init file for $DIR_NAME"
echo $FINAL_PATH
echo $FILE_NAME
$(mkdir $FINAL_PATH)
echo "$FILE_VALUE" > $FILE_NAME