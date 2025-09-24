main:
	g++ -c main.cpp src/hash.cpp src/io.cpp
	g++ -o hashFunkcija main.o hash.o io.o
	./hashFunkcija.exe

run: 
	./hashFunkcija.exe

clean:
	del *.o *.exe

tests:
	g++ -O3 -c src/tests.cpp src/hash.cpp src/io.cpp
	g++ -O3 -o tests tests.o hash.o io.o
	./tests.exe