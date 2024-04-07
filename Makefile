CC = g++
CFLAGS = --std=c++17
SINGLELINKEDLIST = DataStructure/LinkedList/SingleLinkedList

main.out: main.o $(SINGLELINKEDLIST).o
	$(CC) $(CFLAGS) main.o $(SINGLELINKEDLIST).o -o main.out

main.o: main.cpp $(SINGLELINKEDLIST).cpp
	$(CC) $(CFLAGS) -c main.cpp

$(SINGLELINKEDLIST).o: $(SINGLELINKEDLIST).cpp
	$(CC) $(CFLAGS) -c $(SINGLELINKEDLIST).cpp -o $(SINGLELINKEDLIST).o

clean:
	rm main.out main.o $(SINGLELINKEDLIST).o