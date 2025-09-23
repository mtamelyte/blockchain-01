main:
	g++ -c main.cpp src/hash.cpp src/io.cpp
	g++ -o hashFunkcija main.o hash.o io.o
	./hashFunkcija.exe

run: 
	./main.exe

clean:
	del *.o *.exe