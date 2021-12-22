test_recherche.out: bin/recherche.o bin/main.o
	gcc bin/recherche.o bin/main.o -o test_recherche.out -Wall

bin/recherche.o: src/recherche.c include/recherche.h
	gcc -c src/recherche.c -o bin/recherche.o -Wall

bin/main.o: src/main.c
	gcc -c src/main.c -o bin/main.o -Wall