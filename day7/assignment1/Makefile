CXX = g++
EXENAME = main
SRC = src
INC = include

all: main.o libclasses.so
	$(CXX) main.o -L. -lclasses -o $(EXENAME)

main.o: $(SRC)/main.cpp libclasses.so $(INC)/include.h
	$(CXX) -c $(SRC)/main.cpp -I include -o main.o

libclasses.so: $(SRC)/classes.cpp $(INC)/classes.h
	$(CXX) --shared $(SRC)/classes.cpp -I $(INC) -fPIC -o libclasses.so