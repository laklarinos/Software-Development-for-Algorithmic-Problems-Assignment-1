CC = g++ -g -std=c++11 

lsh: main.o parsingInit.o hashTable.o linkedList.o others.o

	$(CC) -o lsh main.o parsingInit.o hashTable.o linkedList.o others.o

main.o: main.cpp others.cpp parsingInit.cpp hashTable.cpp

	$(CC) -g -c main.cpp others.cpp parsingInit.cpp hashTable.cpp

others.o: others.cpp

	$(CC) -g -c others.cpp

parsingInit.o: parsingInit.cpp others.cpp

	$(CC)   -c parsingInit.cpp others.cpp

hashTable.o: hashTable.cpp others.cpp linkedList.cpp

	$(CC)   -c hashTable.cpp others.cpp linkedList.cpp

linkedList.o: linkedList.cpp others.cpp

	$(CC)   -c linkedList.cpp others.cpp

run:

	./lsh -i input_small_id_emiris -q query_small_id -k 10 -L 10 -o output.txt -N 10 -R 10

clean: 

	rm -f *.o

	
	

