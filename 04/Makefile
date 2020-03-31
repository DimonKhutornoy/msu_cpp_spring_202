all: my_prog

my_prog: test.o serial.o 
		g++ -o my_prog test.o serial.o

serial.o: serial.cpp serial.h
		g++ -c serial.cpp

test.o: test.cpp serial.h
		g++ -c test.cpp
		
run:	my_prog
		./my_prog

clean:
		rm -rf *.o my_prog
		rm -rf *.stackdump my_prog
		rm -rf *.exe my_prog