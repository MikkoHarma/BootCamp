CXX = g++
EXENAME = main
SRC = src
INC = include

all: main.o mylib.so
	$(CXX) main.o -L. -lmylib -o $(EXENAME)

main.o: $(SRC)/main.cpp mylib.so $(INC)/include.h
	$(CXX) -c $(SRC)/main.cpp -I include -o main.o

mylib.so: $(SRC)/mylib.cpp $(INC)/mylib.h
	$(CXX) --shared $(SRC)/mylib.cpp -I $(INC) -fPIC -o mylib.so	