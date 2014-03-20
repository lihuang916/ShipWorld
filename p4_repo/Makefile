CC=g++
CFLAG=-c -Wall -std=c++11

.PHONY: clean all

all: Geometry.o Navigation.o Sim_object.o Island.o Track_base.o Ship.o Tanker.o Warship.o Cruiser.o Model.o Controller.o Ship_factory.o go

Geometry.o:	Geometry.cpp
	$(CC) $(CFLAG) Geometry.cpp

Navigation.o:	Navigation.cpp
	$(CC) $(CFLAG) Navigation.cpp

Sim_object.o:	Sim_object.cpp
	$(CC) $(CFLAG) Sim_object.cpp

Island.o:	Island.cpp
	$(CC) $(CFLAG) Island.cpp

Track_base.o:	Track_base.cpp
	$(CC) $(CFLAG) Track_base.cpp

Ship.o: 	Ship.cpp
	$(CC) $(CFLAG) Ship.cpp

Tanker.o:	Tanker.cpp
	$(CC) $(CFLAG) Tanker.cpp

Warship.o:	Warship.cpp
	$(CC) $(CFLAG) Warship.cpp

Cruiser.o:	Cruiser.cpp
	$(CC) $(CFLAG) Cruiser.cpp

Model.o:	Model.cpp
	$(CC) $(CFLAG) Model.cpp

Controller.o:	Controller.cpp
	$(CC) $(CFLAG) Controller.cpp

Ship_factory.o:	Ship_factory.cpp
	$(CC) $(CFLAG) Ship_factory.cpp

go:	*.o
	$(CC) *.o p4_main.cpp -o go
    
clean:
	rm -rf *.o
