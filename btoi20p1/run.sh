#!/bin/bash
echo 'custom_judge: grader.py
unbuffered: true
archive: data.zip
test_cases:' > init.yml


# N <= 64
echo '- batched:' >> init.yml
for((i=0;i<62;i++)); do
	echo "  - {in: data/$i.in}" >> init.yml
done
echo '  points: 9' >> init.yml


# N <= 125
echo '- batched:' >> init.yml
for((i=62;i<106;i++)); do
	echo "  - {in: data/$i.in}" >> init.yml
done
echo '  points: 13' >> init.yml


# N <= 1000
echo '- batched:' >> init.yml
for((i=106;i<154;i++)); do
	echo "  - {in: data/$i.in}" >> init.yml
done
echo '  points: 21' >> init.yml


# N <= 1000000000
echo '- batched:' >> init.yml
for((i=154;i<201;i++)); do
    echo "  - {in: data/$i.in}" >> init.yml
done
echo '  points: 24' >> init.yml


# other
echo '- batched:' >> init.yml
for((i=201;i<=1255;i++)); do
    echo "  - {in: data/$i.in}" >> init.yml
done
echo '  points: 33' >> init.yml


zip -r data.zip data/*
