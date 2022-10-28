#/bin/bash

make && ./account > mine.log

sleep 0.1

cat mine.log | head -51 > mine

cat mine.log | tail -8 | sort >> mine

cat 19920104_091532.log | awk '{printf "%s\n", $2}' > notMy

cat mine | awk '{printf "%s\n", $2}' > my

diff notMy my

rm my notMy mine