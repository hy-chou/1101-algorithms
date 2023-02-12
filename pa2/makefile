# ******************************************************************************
# File       [makefile]
# Author     [HsuanYu CHOU]
# Synopsis   [The makefile for MPS program]
# Modify     [2021-11-20 HsuanYu CHOU]
# ******************************************************************************

CC = g++
CFLAGS = -Wall -Werror -Wextra -c
OFLAGS = -O2

all	: bin/mps

bin/mps	: src/mps.o src/main.o
	$(CC) $(OFLAGS) src/mps.o src/main.o -o bin/mps
src/main.o 	   	: src/main.cpp
	$(CC) $(CFLAGS) $(OFLAGS) $< -o $@
src/mps.o	: src/mps.cpp src/mps.h
	$(CC) $(CFLAGS) $(OFLAGS) $< -o $@

.PHONY : clean fclean test

clean:
	rm src/*.o bin/*
fclean:
	rm -rf src/*.o bin/*
test:
	./bin/mps inputs/12.in 12.out