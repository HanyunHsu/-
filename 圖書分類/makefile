.PHONY: clean stat 

all: directories ut_all

ut_all:
	g++ -std=c++11 -Wfatal-errors test/test_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin/

stat:
	wc -l src/* test/*
