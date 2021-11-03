CC = g++ -g -std=c++11 

main.o: main.cpp others.cpp parsingInit.cpp hashtable.cpp

	$(CC) -g -c main.cpp others.cpp parsingInit.cpp hashtable.cpp

hashtable.o: hashtable.cpp .cpp linkedlist.cpp others.cpp

	$(CC) -c hashtable.cpp linkedlist.cpp others.cpp

linkedlist.o: linkedlist.cpp others.cpp

	$(CC) -c linkedlist.cpp others.cpp

others.o: others.cpp

	$(CC) -c others.cpp

parsingInit.o: parsingInit.cpp others.cpp

	$(CC) -c others.cpp parsingInit.cpp

lsh: main.o hashtable.o others.o linkedlist.o parsingInit.o

	$(CC) -o lsh main.o hashtable.o others.o linkedlist.o parsingInit.o

clean: 

	rm -f *.o

run:
	./lsh -i input_small_id -q query_small_id -k 10 -L 10 -o output.txt -N 10 -R 10
	

