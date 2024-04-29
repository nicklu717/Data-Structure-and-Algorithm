CC = g++
CFLAGS = --std=c++17
SINGLELINKEDLIST = DataStructure/LinkedList/SingleLinkedList
CURRENT_DIR = $(shell pwd)
VCPKG_DIR = $(CURRENT_DIR)/tools/vcpkg/installed/arm64-osx

main: main.out
.PHONY: main

main.out: main.o $(SINGLELINKEDLIST).o
	$(CC) $(CFLAGS) main.o $(SINGLELINKEDLIST).o -o main.out

main.o: main.cpp $(SINGLELINKEDLIST).cpp
	$(CC) $(CFLAGS) -c main.cpp

tests: tests.out
.PHONY: tests

tests.out: tests.o $(SINGLELINKEDLIST).o
	$(CC) $(CFLAGS) tests.o $(SINGLELINKEDLIST).o -o tests.out -L $(VCPKG_DIR)/lib/ -l gtest -L $(VCPKG_DIR)/lib/manual-link/ -l gtest_main

tests.o: tests.cpp $(SINGLELINKEDLIST).cpp
	$(CC) $(CFLAGS) -c tests.cpp -I $(VCPKG_DIR)/include/

$(SINGLELINKEDLIST).o: $(SINGLELINKEDLIST).cpp
	$(CC) $(CFLAGS) -c $(SINGLELINKEDLIST).cpp -o $(SINGLELINKEDLIST).o

clean:
	rm main.out main.o tests.out tests.o $(SINGLELINKEDLIST).o