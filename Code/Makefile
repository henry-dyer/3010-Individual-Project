CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: game

clean:
	rm game Board.o GenBoard.o CVBoard.o Square.o

game: main.cpp Board.o GenBoard.o CVBoard.o Square.o
	$(CXX) $(CXXFLAGS) main.cpp Board.o GenBoard.o CVBoard.o Square.o -o game

Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c Board.cpp

GenBoard.o: GenBoard.cpp
	$(CXX) $(CXXFLAGS) -c GenBoard.cpp

CVBoard.o: CVBoard.cpp
	$(CXX) $(CXXFLAGS) -c CVBoard.cpp

Square.o: Square.cpp
	$(CXX) $(CXXFLAGS) -c Square.cpp