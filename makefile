all: dir_info.c
	gcc dir_info.c

run: a.out
	./a.out

clean:
	rm a.out
