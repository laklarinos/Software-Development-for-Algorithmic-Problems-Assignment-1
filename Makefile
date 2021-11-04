CC = g++ -g -std=c++11 

lsh: main.o parsinginit.o hashtable.o linkedlist.o others.o

	$(CC) -o lsh main.o parsinginit.o hashtable.o linkedlist.o others.o -lm

main.o: main.cpp others.cpp parsinginit.cpp hashtable.cpp

	$(CC) -g -c main.cpp others.cpp parsinginit.cpp hashtable.cpp

others.o: others.cpp

	$(CC) -g -c others.cpp

parsinginit.o: parsinginit.cpp others.cpp

	$(CC)   -c parsinginit.cpp others.cpp

hashtable.o: hashtable.cpp others.cpp linkedlist.cpp

	$(CC)   -c hashtable.cpp others.cpp linkedlist.cpp

linkedlist.o: linkedlist.cpp others.cpp

	$(CC)   -c linkedlist.cpp others.cpp

run:

	./lsh -i input_small_id_emiris -q query_small_id -k 10 -L 10 -o output.txt -N 2 -R 10000

clean: 

	rm -f *.o

	
	

