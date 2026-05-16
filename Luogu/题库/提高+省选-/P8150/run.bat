@echo off
cd "d:\Files\20251007_after\À¶\P8150\"
g++ -std=c++14 -O2 -o P8150 P8150.cpp lib.cpp "-Wl,--stack=2048000000"
P8150