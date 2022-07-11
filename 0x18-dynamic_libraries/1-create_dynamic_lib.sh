#!/bin/bash

gcc -Wall -Wextra -Werror -pedantic -fPIC -c *.c
gcc -shared -Wl,-soname=liball.so -o liball.so *.o
