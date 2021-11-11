CC = g++ -g -std=c++11 

cluster: main.o parsinginit.o hashtable.o linkedlist.o others.o cluster.o

	$(CC) -o cluster main.o parsinginit.o hashtable.o linkedlist.o others.o cluster.o -lm

cluster.o: cluster.cpp hashtable.cpp 

	$(CC) -c cluster.cpp hashtable.cpp

main.o: main.cpp others.cpp parsinginit.cpp hashtable.cpp

	$(CC) -c main.cpp others.cpp parsinginit.cpp hashtable.cpp

others.o: others.cpp

	$(CC) -c others.cpp

parsinginit.o: parsinginit.cpp others.cpp

	$(CC) -c parsinginit.cpp others.cpp

hashtable.o: hashtable.cpp others.cpp linkedlist.cpp

	$(CC) -c hashtable.cpp others.cpp linkedlist.cpp

linkedlist.o: linkedlist.cpp others.cpp

	$(CC) -c linkedlist.cpp others.cpp

run:

	./cluster –i input_small_id_emiris –c cluster.conf -o output.txt -Complete no -m Classic

valgrind:

	valgrind --leak-check=yes ./cluster –i input_small_id_emiris –c cluster.conf -o output.txt -Complete no -m Classic

clean: 

	rm -f *.o

	
	

