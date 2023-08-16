#!/bin/sh

if [ $# -lt 2 ]
then
    echo "Please specify 2 arguments"
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d ${filesdir} ]
then
    echo "${filesdir} is not a directory in the file system"
    exit 1
fi

num_files=$(ls -lA ${filesdir} | grep "^-" | wc -l)
num_matching_lines=$(grep -r ${searchstr} ${filesdir} | wc -l)
echo "The number of files are ${num_files} and the number of matching lines are ${num_matching_lines}"
