echo -e "Identify any line with two or more vowels in a row.\n"
grep -E '[aeiouAEIOU]{2}' mysampledata.txt
echo -e "\n"
#egrep '{aeiou}{2,}' mysampledata.txt
echo -e "Any line with a 2 on it which is not the end of the line.\n"
egrep '2.+' mysampledata.txt
echo -e "\n"
echo -e "Number 2 as the last character on the line"
egrep '2$' mysampledata.txt
echo -e "\n"
echo -e "Each line which contains either 'is' or 'go' or 'or'.\n"
egrep 'or|is|go' mysampledata.txt
echo -e "\n"
echo -e "Maybe we wish to see orders for everone who's name begins with A - K\n"

