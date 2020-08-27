cat /etc/passwd | sed "/^#/d;s/:.*//g" | sed -n "n;p" | rev | sort -r | head -n $FT_LINE2 | tail -n $(($FT_LINE2-$FT_LINE1+1)) | sed "s/$/, /g" | tr -d '\n' | rev | sed "s/ ,/./" | rev | tr -d '\n'
