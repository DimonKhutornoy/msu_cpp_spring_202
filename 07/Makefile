all: my_prog

my_prog: test.o
		g++ -o my_prog test.o


test.o: test.cpp vector.h allocator.h iterator.h
		g++ -c test.cpp
		
run:	my_prog
		./my_prog

clean:
		rm -rf *.o my_prog
		rm -rf *.stackdump my_prog
		rm -rf *.exe my_prog