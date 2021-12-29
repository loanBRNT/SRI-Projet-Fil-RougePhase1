prog.out: bin/recherche.o bin/main.o bin/admin.o bin/comparaison.o bin/indexation.o bin/img.o bin/pile_Img.o bin/pile_Audio.o bin/descripteurAudio.o
	gcc bin/recherche.o bin/main.o bin/admin.o bin/comparaison.o bin/indexation.o bin/img.o bin/pile_Img.o bin/pile_Audio.o bin/descripteurAudio.o -o prog.out -lm

bin/recherche.o: src/recherche.c include/recherche.h
	gcc -c src/recherche.c -o bin/recherche.o -Wall

bin/admin.o: src/admin.c include/admin.h
	gcc -c src/admin.c -o bin/admin.o -Wall

bin/comparaison.o: src/comparaison.c include/comparaison.h
	gcc -c src/comparaison.c -o bin/comparaison.o -Wall

bin/indexation.o: src/indexation.c include/indexation.h
	gcc -c src/indexation.c -o bin/indexation.o -Wall

bin/img.o: src/img.c include/img.h
	gcc -c src/img.c -o bin/img.o

bin/pile_Img.o: src/pile_Img.c include/pile_Img.h
	gcc -c src/pile_Img.c -o bin/pile_Img.o -Wall

bin/pile_Audio.o: src/pile_Audio.c include/pile_Audio.h
	gcc -c src/pile_Audio.c -o bin/pile_Audio.o -Wall

bin/descripteurAudio.o: src/descripteurAudio.c include/descripteurAudio.h
	gcc -c src/descripteurAudio.c -o bin/descripteurAudio.o -Wall

bin/main.o: src/main.c
	gcc -c src/main.c -o bin/main.o -Wall