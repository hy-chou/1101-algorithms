CC = g++
CFLAGS = -Wall -Werror -Wextra -c
OFLAGS = -O3

all	: bin/cb

bin/cb	: src/cb.o src/main.o
	$(CC) $(OFLAGS) src/cb.o src/main.o -o bin/cb
src/main.o 	   	: src/main.cpp
	$(CC) $(CFLAGS) $(OFLAGS) $< -o $@
src/cb.o	: src/cb.cpp src/cb.h
	$(CC) $(CFLAGS) $(OFLAGS) $< -o $@

.PHONY : clean ready test

clean:
	rm src/*.o bin/*
ready:
	rm src/*.o
test:
	./bin/cb inputs/public_case_1.in outputs/1.out
	./bin/cb inputs/public_case_2.in outputs/2.out
	./bin/cb inputs/public_case_3.in outputs/3.out
	./bin/cb inputs/public_case_4.in outputs/4.out
	./bin/cb inputs/public_case_5.in outputs/5.out
	./bin/cb inputs/public_case_7.in outputs/7.out
	./bin/cb inputs/public_case_8.in outputs/8.out
	./bin/cb inputs/pdf_case_d.in outputs/d.out
	./bin/cb inputs/pdf_case_u.in outputs/u.out
	head -n 1 outputs/*