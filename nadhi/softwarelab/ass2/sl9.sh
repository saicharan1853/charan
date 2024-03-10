echo 
echo "9. Use grep or egrep to pick out all the words that start with f or F"
echo
grep -o -n "[fF]\w*" poem.txt
