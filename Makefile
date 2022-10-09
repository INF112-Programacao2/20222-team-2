.PHONY: all run clean

all:
	g++ -o bin/xadrez src/*.cpp

run:
	@./bin/xadrez

clean:
	rm bin/*
