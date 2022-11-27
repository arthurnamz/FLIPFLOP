#!/bin/bash

SYSTEMC_HOME=~/systemc/systemc-2.3.3
input=$1
output=$2

g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -o $output $input -lsystemc -lm
