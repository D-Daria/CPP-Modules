#! /bin/bash

make

printf "./PmergeMe 3 2 1 0"
./PmergeMe 3 2 1 0
printf "\n"
sleep 0.3

printf "./PmergeMe 3 5 9 7 4"
./PmergeMe 3 5 9 7 4
printf "\n"
sleep 0.3

printf "./PmergeMe `ruby -e "puts (1..10000).to_a.shuffle.join(' ')"`"
./PmergeMe `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`
printf "\n"
sleep 0.3

printf "./PmergeMe `ruby -e "puts (1..55).to_a.shuffle.join(' ')"`"
./PmergeMe `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`
printf "\n"
sleep 0.3

printf "./PmergeMe `ruby -e "puts (1..201).to_a.shuffle.join(' ')"`"
./PmergeMe `ruby -e "puts (1..201).to_a.shuffle.join(' ')"`
printf "\n"
sleep 0.3

printf "./PmergeMe `ruby -e "puts (0..1000).to_a.shuffle.join(' ')"`"
./PmergeMe `ruby -e "puts (0..1000).to_a.shuffle.join(' ')"`
printf "\n"
sleep 0.3

printf "./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`"
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
printf "\n"
sleep 0.3

printf "./PmergeMe `ruby -e "puts (0..5000).to_a.shuffle.join(' ')"`"
./PmergeMe `ruby -e "puts (0..5000).to_a.shuffle.join(' ')"`
printf "\n"
sleep 0.3

printf "./PmergeMe `ruby -e "puts (1..10000).to_a.shuffle.join(' ')"`"
./PmergeMe `ruby -e "puts (1..10000).to_a.shuffle.join(' ')"`
printf "\n"
sleep 0.3
