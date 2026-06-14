build:
	gcc -Wall -Wextra -Wpedantic -ansi ./src/aascii.c -o aascii

clean:
	-rm aascii
