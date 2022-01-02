for i in data/*; do
	mv $i $i.in
	# j=$(echo $i | sed -e 's/^[^0-9]*\([0-9][0-9]*\).*/\1/')
	# j=$(echo $j | sed 's/^0*//')
	# mv $i data/$j
	# echo $i data/$j
done