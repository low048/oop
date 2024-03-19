.PHONY: all vector list deque clean

all: vector list deque

vector:
	g++ ./include/*.cpp ./vector/*.cpp -o vector.exe

list:
	g++ ./include/*.cpp ./list/*.cpp -o list.exe

deque:
	g++ ./include/*.cpp ./deque/*.cpp -o deque.exe

clean:
	rm -f vector.exe list.exe deque.exe
