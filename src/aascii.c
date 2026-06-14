
#include <stdio.h>

typedef enum { false, true } bool;

void scanFile(const char *filepath) {

	int ch;
	size_t line = 1;
	size_t col = 1;

	FILE *file = fopen(filepath, "rb");
	if (!file) {
		printf("Couldn't read '%s'!\n", filepath);
		return;
	}

	while ((ch = fgetc(file)) != EOF) {

		if ((unsigned char)ch > 127) {

			printf(
				"%s: %lu-%lu: 0x%02X\n",
				filepath, (unsigned long)line, (unsigned long)col, (unsigned char)ch
			);

		}

		if (ch == '\n') { line++; col = 1; }
		else            { col++; }

	}

	fclose(file);

}

int main(int argc, char** argv) {

	int i;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
		return 1;
	}

	for (i = 1; i < argc; i++) {
		scanFile(argv[i]);
	}

	return 0;

}

