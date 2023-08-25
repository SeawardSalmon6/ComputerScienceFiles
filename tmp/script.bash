#!/bin/bash

get_value_from_arg() {
  echo "${1#*=}"
}

remove_arg() {
  for arg in $@; do
    case $arg in
      -r=*)
        echo "$(get_value_from_arg $arg)"
      ;;
    esac
  done
}

remove_arg 1 2 3 4 5 3 -r=asdb
