#! /bin/bash

# Updates a "#define _TIMESTAMP" line in a file. Copy of original file
# has the same name but suffixed with a "~", for example "myfile.c~".

fname=$1

# Ensure we can work with the specified file
if [[ ! -f ${fname} || ! -r ${fname} || ! -w ${fname} ]]; then
  echo "Error setting timestamp for file \"${fname}\"" >&2
  exit 1
fi

# Set the timestamp and the find and replace strings
timestamp=`date +%s`
fstr1="^[ ]*#[ ]*define [ ]*_TIMESTAMP$"
rstr1="#define _TIMESTAMP "

# Copy the original file
cp ${fname} ${fname}~

# A little extra going on here, hence the two seds. The first sed
# only acts when a "#define _TIMESTAMP" has no trailing text and
# ends at the end of line; when that happens it simply tacks on a
# single whitespace. The second sed looks for "#define _TIMESTAMP "
# and replaces everything after the trailing whitespace with the new
# timestamp text. In the unlikely event there's a similar macro
# definition in the file (e.g. "#define _TIMESTAMP_FOO") it won't be
# modified by this script. TODO Probably a cleaner way of doing this.

cat ${fname}~ \
  | sed -e "s/${fstr1}/${rstr1} /" \
  | sed -e "s/${rstr1} .*/#define _TIMESTAMP    ${timestamp}/" \
  > ${fname}

if [ $? -eq 0 ]; then
  exit 0
else
  mv ${fname}~ ${fname}
  echo "Error setting timestamp for file \"${fname}\"" >&2
  exit 1
fi
