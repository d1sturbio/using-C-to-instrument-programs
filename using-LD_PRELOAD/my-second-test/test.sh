#!/bin/bash
gcc fake-lib/fake.c -o fake-lib/fake -fPIC -shared -ldl 2&>/dev/null
clang main.c -o program
LD_PRELOAD=`pwd`/fake-lib/fake ./program
