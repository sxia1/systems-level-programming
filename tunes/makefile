all: main.o linked_list.o music_library.o
	gcc -o sound music_library.o linked_list.o main.o

main.o: main.c linked_list.h music_library.h
	gcc -c main.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

music_library.o: music_library.c music_library.h linked_list.h
	gcc -c music_library.c

run:
	./sound

clean:
	rm -rf *.o
	rm -rf *~
