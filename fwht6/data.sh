#!/bin/bash
name="fwht6"
echo $name

g++ ./6.cpp -DONLINE_JUDGE -DLOCAL --std=c++17 -O2 -o fast || { echo 'fast comp failed'; exit 1;}
g++ ./gen.cpp --std=c++17 -O2 -o gen || { echo 'gen comp failed';  exit 1;}

mkdir $name
mkdir $name/data
rm $name/data/*

echo 'archive: data.zip
test_cases:' > $name/init.yml
i=1


## SUBTASK 1 (6)
t=6
echo '- batched:' >> $name/init.yml
for((v=20;v<=200000;i++,v*=10))
do
    echo $i $t
    ./gen $v $t > $name/data/$i.in || { echo 'gen run failed'; exit 1;}
    ./fast < $name/data/$i.in > $name/data/$i.out || { echo 'fast run failed'; exit 1;}
    echo "  - {in: data/$i.in, out: data/$i.out}" >> $name/init.yml
done
echo '  points: 10' >> $name/init.yml


zip -r $name/data.zip $name/data/*