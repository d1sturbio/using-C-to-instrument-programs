#!/bin/bash
gcc fake-lib/fake-rand.c -o fake-lib/fake-rand -fPIC -shared -ldl
clang main.c -o program
LD_PRELOAD=`pwd`/fake-lib/fake-rand ./program
