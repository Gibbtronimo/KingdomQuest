default: myprog

myprog: mergeTest.o mergeClasses.o
	g++ mergeTest.o mergeClasses.o -o myprog

mergeTest.o: mergeTest.cpp
	g++ -c mergeTest.cpp

mergeClasses.o: mergeClasses.cpp mergeClasses.h
	g++ -c mergeClasses.cpp
	
clean:
	rm -rf *.o myprog