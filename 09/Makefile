all: my_prog

my_prog: test.o mysort.o 
		g++ -o my_prog test.o mysort.o

mysort.o: mysort.cpp mysort.h
		g++ -c mysort.cpp

test.o: test.cpp mysort.h
		g++ -c test.cpp
		
run:	my_prog
		./my_prog

clean:
		rm -rf *.o my_prog
		rm -rf *.stackdump my_prog
		rm -rf *.exe my_prog