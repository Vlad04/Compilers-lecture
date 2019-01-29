#!/bin/bash

functions=$(grep -P -o '(?<=<)[a-zA-Z]*?(?=>:)' "$1")
functions_count=$(echo "$functions" | wc -l)
foo_instructions=$(awk -F"\n" -v RS="\n\n" '$1 ~ /foo/' "$1" | cut -b 32-50 | cut -d' ' -f1 | sed '/^$/d' | sed 's/[^a-zA-Z0-9]//g')
main_instructions=$(awk -F"\n" -v RS="\n\n" '$1 ~ /main/' "$1" | cut -b 32-50 | cut -d' ' -f1 | sed '/^$/d'| sed 's/[^a-zA-Z0-9]//g')
count_instructions=$(echo "$foo_instructions"$'\n'"$main_instructions"| sort -u | wc -l)
echo "You have $count_instructions kinds of instructions on this object file: "
echo "$foo_instructions"$'\n'"$main_instructions"|sort | uniq -c | awk '{print "\t"$2"\t: executed "$1" times"}'
echo "You have $functions_count functions:"
paste <(echo "$functions") <(grep -wF "$functions" "$1" | awk '{if ($1 !~ ":" && $1 != "Disassembly") {print $1}}') | awk '{print "\t"$1"\t: Located at "$2" addr"}'
exit 0 
