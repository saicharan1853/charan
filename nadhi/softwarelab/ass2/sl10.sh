echo
echo "10. Use grep or egrep to pick out lines that uses first letter alliteration - starting two words with the same letter. ( .* dot and then asterisk will find any characters in the search text)"
echo 
egrep -n "\b([a-zA-Z])\w*\b \1\w*" poem.txt
