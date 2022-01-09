interface.out: bin/interface.o bin/pwd.o bin/main.o
	gcc bin/interface.o bin/pwd.o bin/main.o bin/admin.o -o interface.out -Wall

bin/interface.o: src/interface.c include/interface.h
	gcc -c src/interface.c -o bin/interface.o -Wall

bin/pwd.o: src/pwd.c include/pwd.h
	gcc -c src/pwd.c -o bin/pwd.o -Wall

bin/admin.o : src/admin.c
	gcc -c src/admin.c -o bin/admin.o -Wall

bin/main.o : src/main.c
	gcc -c src/main.c -o bin/main.o -Wall