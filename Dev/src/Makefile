

test: main.o indexation.o admin.o descripteurAudio.o pile_Audio.o img.o pile_Img.o 
	gcc -g -o test.out main.o indexation.o admin.o descripteurAudio.o pile_Audio.o img.o pile_Img.o  -lm
	./test.out

indexation.o: indexation.c ../include/indexation.h
	gcc -c indexation.c -o indexation.o  -W -Wall -lm

admin.o: admin.c ../include/admin.h
	gcc -c admin.c -o admin.o  -W -Wall -lm

descripteurAudio.o: descripteurAudio.c ../include/descripteurAudio.h
	gcc -c descripteurAudio.c -o descripteurAudio.o  -W -Wall -lm

img.o: img.c ../include/img.h
	gcc -c img.c -o img.o  -W -Wall -lm

pile_Audio.o: pile_Audio.c ../include/pile_Audio.h 
	gcc -c pile_Audio.c -o pile_Audio.o -W -Wall -lm
				
pile_Img.o: pile_Img.c ../include/pile_Img.h 
	gcc -c pile_Img.c -o pile_Img.o -W -Wall -lm

main.o: main.c ../include/admin.h ../include/descripteurAudio.h ../include/img.h ../include/indexation.h
	gcc -o main.o -c main.c -W -Wall -lm
