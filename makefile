all: main.o sieve.o
	gcc -o sifting sieve.o main.o -lm

main.o: main.c sieve.h
	gcc -c main.c

sieve.o: sieve.h sieve.c
	gcc -c sieve.c

clean:
	rm *.o
	rm *~

run:
	./sifting
