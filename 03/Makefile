all: my_prog

my_prog: test.o mtxlib.o 
		g++ -o my_prog test.o mtxlib.o

mtxlib.o: mtxlib.cpp mtxlib.h
		g++ -c mtxlib.cpp

test.o: test.cpp mtxlib.h
		g++ -c test.cpp

clean:
		rm -rf *.o my_prog
		rm -rf *.stackdump my_prog
		rm -rf *.exe my_prog