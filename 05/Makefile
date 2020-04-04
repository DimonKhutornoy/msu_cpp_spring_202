all: my_prog

my_prog: test.o bigint.o 
		g++ -o my_prog test.o bigint.o

bigint.o: bigint.cpp bigint.h
		g++ -c bigint.cpp

test.o: test.cpp bigint.h
		g++ -c test.cpp
		
run:	my_prog
		./my_prog

clean:
		rm -rf *.o my_prog
		rm -rf *.stackdump my_prog
		rm -rf *.exe my_prog