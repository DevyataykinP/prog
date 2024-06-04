all: main

main: main.o varint/varint.o
	gcc -Wall -Werror -I varint main.o varint/varint.o -o main -g -O2

main.o: main.c
	gcc -Wall -Werror -I varint -c main.c -o main.o -g

varint/varint.o: varint/varint.c
	gcc -Wall -Werror -I varint -c varint/varint.c -o varint/varint.o -g

.PHONY: clean

clean:
	rm main *.o varint/*.o