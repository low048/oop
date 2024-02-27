all: program.exe

program.exe: main.cpp funkcijos.cpp studentas.cpp
	g++ main.cpp funkcijos.cpp studentas.cpp -o program.exe
