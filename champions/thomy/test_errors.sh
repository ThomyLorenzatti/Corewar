#!/bin/bash

SUCCESS=0
FAILS=0
FAIL_NAME=""

if [ -z "$1" ]
then
printf "You must put asm exe in argument\n"
exit 84
fi

$(rm -rf ./*.cor)

for file in "./error"/*.s
do
    $(./$1 "$file")
    if [ $? -ne 84 ]
    then
        ((FAILS+=1))
        FAIL_NAME+="{$file}\n"
    else
	((SUCCESS+=1))
    fi
done

$(rm -rf *.cor)

echo -ne "$FAIL_NAME"
echo -e "SUCCESS: $SUCCESS"
echo -e "FAILS: $FAILS"
