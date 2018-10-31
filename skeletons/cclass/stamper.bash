#! /bin/bash

fname=$1

if [[ ! -f ${fname} || ! -r ${fname} || ! -w ${fname} ]]; then
  echo "Error setting timestamp for file \"${fname}\"" >&2
  exit 1
fi

timestamp=`date +%s`
fstr1="^[ ]*#[ ]*define [ ]*_TIMESTAMP$"
rstr1="#define _TIMESTAMP "

cp ${fname} ${fname}~

cat ${fname}~ \
  | sed -e "s/${fstr1}/${rstr1} /" \
  | sed -e "s/${rstr1} .*/#define _TIMESTAMP    ${timestamp}/" \
  > ${fname}

if [ $? -eq 0 ]; then
  :
else
  mv ${fname}~ ${fname}
  echo "Error setting timestamp for file \"${fname}\"" >&2
fi
