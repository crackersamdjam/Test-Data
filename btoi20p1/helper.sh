for v in 64 125 1000 1000000000; do
	for i in data/*; do
		#echo $i
		#echo $i | sed -e 's/^[^0-9]*\([0-9][0-9]*\).*/\1/'
		n=$(cat $i | sed -e 's/^[^0-9]*\([0-9][0-9]*\).*/\1/')
		if [ $n -gt $v ]; then
			echo $v $i
			break
		fi
	done
done
