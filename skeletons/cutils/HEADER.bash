#! /bin/bash

_I_AM='cutilgen'
_VERSION='XXX'

function print_usage {
  cat <<_TEXT
Usage: $_I_AM [OPTIONS] <name>
Generates a subdirectory <class_name> with a development skeleton
useful for developing C utility functions.
Options:
-h        Print this help message to stdout and exit.
-t <tag>  Use <tag> (instead of <class_name>) to prefix class methods.
-v        Print the version information to stdout and exit.
-d        Dry run. Print out a few variables then exit.
_TEXT
}

class_name=''
class_tag=''
class_version="0.0-alpha"
#dry_run_flag=0 <- leave this unset

# Process the command line options
while getopts ":dht:v" opt; do
  case $opt in
    d )
      dry_run_flag=1
      ;;
    h )
      print_usage
      exit 0
      ;;
    t )
      #class_tag="$OPTARG"
      # this one replace multiple whitespaces with a single underscore
      class_tag=`echo $OPTARG | sed -e 's/\s\s*/ /g' -e 's/ /_/g'`
      ;;
    v )
      echo "$_I_AM $_VERSION"
      exit 0
      ;;
    \? )
      echo "[ERROR] $_I_AM: Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    : )
      echo "[ERROR] $_I_AM: Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done

# Remove the command line options from $@
shift $(($OPTIND - 1))

if [ z"$1" = z ]; then
  echo "[ERROR] $_I_AM: Need to specify class name." >&2
  print_usage
  exit 1
fi

class_name=`basename "$1"`
class_name=`echo $class_name | sed -e 's/\s\s*/ /g' -e 's/ /_/g'`
class_name_uc=`echo "$class_name" | tr '[:lower:]' '[:upper:]'`
class_tag=${class_tag:=$class_name}

if [ $dry_run_flag ]
then
  cat <<_TEXT
"$_I_AM version $_VERSION"
Requested class name: $class_name
Using class_name_uc : $class_name_uc
Using class_tag     : $class_tag
_TEXT
  exit 0
else
  mkdir -p $class_name
fi
