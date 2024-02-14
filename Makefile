all: vector.exe array.exe

vector.exe: vector.cpp
	g++ vector.cpp -o vector.exe

array.exe: array.cpp
	g++ array.cpp -o array.exe