output: cal.o
	g++ -g -w -std=c++11 -o cal cal.o

cal.o: cal.cpp cmake-build-debug/quadratic.c cmake-build-debug/triples.c cmake-build-debug/sum.c
	g++ -g -w -std=c++11 -c cal.cpp cmake-build-debug/quadratic.c cmake-build-debug/triples.c cmake-build-debug/sum.c

clean:
	rm -rf *.o