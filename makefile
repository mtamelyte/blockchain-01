main:
	g++ -c main.cpp src/hash.cpp
	g++ -o main main.o hash.o
	./main.exe

clean:
	del *.o *.exe