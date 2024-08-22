#!/bin/bash

CFLAGS="-O0 -ggdb -Wall -Wextra"

EXECUTABLE="./itlei"

makeflags=""

if [[ "$1" == "r" ]]; then
    shift
    makeflags+="-B"
fi

if [[ "$1" == "t" ]]; then
    shift
    makeflags+="tests_run"
    EXECUTABLE="./tests_bin"
fi

CFLAGS=$CFLAGS make $makeflags

if [[ "$1" == "db" ]]; then
    shift
    gdb --args ./itlei $@

else

    $EXECUTABLE $@

fi
