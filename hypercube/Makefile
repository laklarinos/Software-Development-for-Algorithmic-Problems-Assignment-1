CC = g++ -g -std=c++11 

cube: main.o parsinginit.o hashtable.o linkedlist.o others.o

	$(CC) -o cube main.o parsinginit.o hashtable.o linkedlist.o others.o -lm

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

	./cube -i input_small_id_emiris -q query_small_id -k 14 -M 10 -probes 2 -o output.txt -N 5 -R 10000

valgrind:

	valgrind --leak-check=full 	./cube -i input_small_id_emiris -q query_small_id -k 14 -M 10 -probes 2 -o output.txt -N 5 -R 10000

clean: 

	rm -f *.o

	
	 

