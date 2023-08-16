if [ $# -lt 2 ]
then
    echo "Please provide two arguments"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p $(dirname "$writefile") && touch ${writefile}
if [ $? -eq 1 ]
then
    echo "Couldn't create ${writefile}"
    exit 1
fi

echo ${writestr} > ${writefile}
