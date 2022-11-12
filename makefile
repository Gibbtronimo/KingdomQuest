default: myprog

myprog: mergeTest.o mergeClasses.o
	g++ -std=c++11 mergeTest.o mergeClasses.o -o myprog

mergeTest.o: mergeTest.cpp
	g++ -std=c++11 -c mergeTest.cpp

mergeClasses.o: mergeClasses.cpp mergeClasses.h
	g++ -std=c++11 -c mergeClasses.cpp
	
clean:
	rm -rf *.o myprog