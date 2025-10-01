main:
	g++ -c main.cpp src/originalHash.cpp src/claudeHash.cpp src/io.cpp
	g++ -o hashFunkcija main.o originalHash.o claudeHash.o io.o
	./hashFunkcija.exe

run: 
	./hashFunkcija.exe

clean:
	del *.o *.exe

tests:
	g++ -O3 -c src/tests.cpp src/originalHash.cpp src/claudeHash.cpp src/io.cpp
	g++ -O3 -o tests tests.o originalHash.o claudeHash.o io.o -lssl -lcrypto
	./tests.exe