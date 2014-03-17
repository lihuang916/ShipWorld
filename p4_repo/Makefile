CC=g++
CFLAG=-c -Wall -std=c++11

.PHONY: clean all

all: Ship

SimO:	Sim_object.cpp
	$(CC) $(CFLAG) Sim_object.cpp

Island:	Island.cpp
	$(CC) $(CFLAG) Island.cpp

Ship: 	Ship.cpp
	$(CC) $(CFLAG) Ship.cpp
clean:
	rm -rf *.o