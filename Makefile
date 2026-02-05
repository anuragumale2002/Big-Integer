# ==========================================
# Name: Anurag Prashant Umale              =
# Student Id: 1887255                      =
# E-mail: aumale@ucsc.edu                  =
# File: Makefile						   =
# Class: CSE 101 Spring 2023               =
# ==========================================

CC = g++
CFLAGS = -std=c++17 -Wall

all: ListTest Arithmetic BigIntegerTest

ListTest: ListTest.o List.o
	$(CC) -o $@ $^

BigIntegerTest: BigIntegerTest.o BigInteger.o List.o
	$(CC) -o $@ $^

Arithmetic: Arithmetic.o BigInteger.o List.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f ListTest Arithmetic BigIntegerTest List *.o

cleanText:
	rm -f *.txt

cleandir:
	rm -r backup

checkMath:
	valgrind --leak-check=full ./Arithmetic in out

checkInteger:
	valgrind --leak-check=full ./BigIntegerTest

checkList:
	valgrind --leak-check=full ./ListTest
