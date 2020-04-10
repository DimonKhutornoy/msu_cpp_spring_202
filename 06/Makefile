all: my_prog

my_prog: test.o format.o 
		g++ -o my_prog test.o format.o

format.o: format.cpp format.h
		g++ -c format.cpp

test.o: test.cpp format.h
		g++ -c test.cpp
		
run:	my_prog
		./my_prog

clean:
		rm -rf *.o my_prog
		rm -rf *.stackdump my_prog
		rm -rf *.exe my_prog