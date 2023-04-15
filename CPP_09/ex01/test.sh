#!/bin/bash

make

printf "./RPN 8 9 * 9 - 9 - 9 - 4 - 1 +\n" #42
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
printf "\n"
sleep 0.3

printf "./RPN 7 7 * 7 -\n"
./RPN "7 7 * 7 -"
printf "\n"
sleep 0.3

printf "./RPN 1 2 * 2 / 2 * 2 4 - +\n"
./RPN "1 2 * 2 / 2 * 2 4 - +"
printf "\n"
sleep 0.3

printf "./RPN (1 + 1)\n"
./RPN "(1 + 1)"
printf "\n"
sleep 0.3

printf "./RPN 5 5 + -9 * -2 -\n"
./RPN "5 5 + -9 * -2 -"
printf "\n"
sleep 0.3

printf "./RPN 0 0 /\n"
./RPN "0 0 /"

