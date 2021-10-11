#!/bin/bash

SUCCESS=0
FAILS=0
RETFAIL=0
FAIL_NAME=""

$(rm -rf ./*.cor)

for file in "./champ"/*.s
do
    $(./asm "$file")
    if [ $? -ne 0 ]
    then
        ((RETFAIL+=1))
    fi
done

for file in "."/*.cor
do
    hexdump -C "$file" > "my_"$(echo "$file" | cut -d '/' -f 2 | cut -d '.' -f 1)
    $(rm -rf "$file")
done

for file in "./champ"/*.s
do
    $(./ref "$file")
done

for file in "."/*.cor
do
    hexdump -C "$file" > "ref_"$(echo "$file" | cut -d '/' -f 2 | cut -d '.' -f 1)
    $(rm -rf "$file")
done

for file in "."/ref_*
do
    $(diff "$file" "./my_"$(echo "$file" | cut -b7-) > /dev/null)
    if [ $? -eq 0 ]
    then
        ((SUCCESS+=1))
    else
        ((FAILS+=1))
        FAIL_NAME+="{$file}\n"
    fi
done

$(rm -rf my_* ref_*)

echo -ne "$FAIL_NAME"
echo -e "SUCCESS: $SUCCESS"
echo -e "FAILS  : $FAILS"
echo -e "RETFAIL: $RETFAIL"
 
