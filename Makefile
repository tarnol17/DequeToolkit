# @file Makefile
# @author Christian McKenzie
# @author Tyson Arnold
# @date 2025-04-25
# @brief Makefile for the deque toolkit

CC = g++
CFLAGS = -Wall -std=c++11

all: deque

deque: main.o deque.o
	$(CC) $(CFLAGS) -o deque main.o deque.o

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp

clean:
	rm -f *.o deque