all: program.exe

program.exe: *.cpp
	g++ *.cpp -o program.exe
