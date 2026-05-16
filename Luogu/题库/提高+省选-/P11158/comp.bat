@echo off
f:
cd "F:\Algorithm_Learning\Luogu\题库\提高+省选-\P11158"
g++ brute.cpp -o brute
g++ E_gen.cpp -o E_gen
g++ P11158.cpp -o P11158
:run
E_gen > "E.in"
brute < "E.in" > "ac.out"
P11158 < "E.in" > "wa.out"
fc "ac.out" "wa.out"