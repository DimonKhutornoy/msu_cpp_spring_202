all: my_prog

my_prog: test.o programmer1.o programmer2.o parce.o 
		g++ -o my_prog test.o programmer1.o programmer2.o parce.o 

programmer1.o: programmer1.cpp programmer1.h
		g++ -c programmer1.cpp
		
programmer2.o: programmer2.cpp programmer2.h
		g++ -c programmer2.cpp

test.o: test.cpp programmer1.h programmer2.h parce.h 
		g++ -c test.cpp
		
parce.o: parce.cpp parce.h
		g++ -c parce.cpp

clean:
		rm -rf *.o my_prog