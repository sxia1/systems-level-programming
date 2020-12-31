all: randfile.o
	gcc -o rand randfile.o

randfile.o: randfile.c
	gcc -c randfile.c

run:
	./rand

clean:
	rm *.o

