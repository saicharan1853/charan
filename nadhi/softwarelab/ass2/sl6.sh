echo 
echo "6. Use grep or egrep to pick out all the lines that do not start with an uppercase letter."
echo 
grep -v -n "^[A-Z]" poem.txt
