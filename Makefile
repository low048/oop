.PHONY: all vector list deque clean

all: vector list deque

vector:
	g++ ./vector/*.cpp -o vector.exe

list:
	g++ ./list/*.cpp -o list.exe

deque:
	g++ ./deque/*.cpp -o deque.exe

clean:
	rm -f vector.exe list.exe deque.exe
