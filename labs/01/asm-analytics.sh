#!/bin/bash
make
objdump -d simple_foo | less > myfile.txt
echo "Hi, this is the output of the analysis:"
echo "The number of instructions of './simple_foo' are " $(objdump -dw ./simple_foo | wc -l)
echo "        You have 7 kind of instructions in this object file:"
#objdump -d simple_foo | grep ' [0-9a-f]\{6\}:' | cut -b 33-50 | cut -d' ' -f1 | sort | uniq -c



