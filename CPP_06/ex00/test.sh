#!/bin/bash

GREEN="\033[32m"
RED="\033[31m"
BLUE="\033[34m"
YELLOW="\033[33m"
NC="\033[0m"

make

printf "${BLUE}./convert 0 ${NC}\n"
./convert 0
sleep 0.3

printf "${BLUE}./convert nan ${NC}\n"
./convert nan
sleep 0.3

printf "${BLUE}./convert 42.0f ${NC}\n"
./convert 42.0f
sleep 0.3

printf "${BLUE}./convert -767868768686878687686 ${NC}\n"
./convert -767868768686878687686
sleep 0.3

printf "${BLUE}./convert -inff ${NC}\n"
./convert -inff
sleep 0.3

printf "${BLUE}./convert +inff ${NC}\n"
./convert +inff
sleep 0.3

printf "${BLUE}./convert nanf ${NC}\n"
./convert nanf
sleep 0.3

printf "${BLUE}./convert -inf ${NC}\n"
./convert -inf
sleep 0.3

printf "${BLUE}./convert +inf ${NC}\n"
./convert +inf
sleep 0.3

printf "${BLUE}./convert -1 ${NC}\n"
./convert -1
sleep 0.3

printf "${BLUE}./convert -0 ${NC}\n"
./convert -0
sleep 0.3

printf "${BLUE}./convert 0.0 ${NC}\n"
./convert 0.0
sleep 0.3

printf "${BLUE}./convert 3.33333333333333333 ${NC}\n"
./convert 3.33333333333333333
sleep 0.3

printf "${BLUE}./convert 2147483647 ${NC}\n"
./convert 2147483647
sleep 0.3

printf "${BLUE}./convert -2147483648 ${NC}\n"
./convert -2147483648
sleep 0.3

printf "${BLUE}./convert 4.2 ${NC}\n"
./convert 4.2
sleep 0.3

printf "${BLUE}./convert -4.2 ${NC}\n"
./convert -4.2
sleep 0.3

printf "${BLUE}./convert -1f ${NC}\n"
./convert -1f
sleep 0.3

printf "${BLUE}./convert 125 ${NC}\n"
./convert 125
sleep 0.3

printf "${BLUE}./convert -5345h ${NC}\n"
./convert -5345h
sleep 0.3
