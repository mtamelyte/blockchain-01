main:
	g++ -c main.cpp src/bitwiseHash.cpp
	g++ -o main main.o bitwiseHash.o
	./main.exe

bitwise:
	g++ -c src/bitwiseHash.cpp
	g++ -o bitwiseHash.o
	./bitwiseHash.exe

run: 
	./main.exe

clean:
	del *.o *.exe