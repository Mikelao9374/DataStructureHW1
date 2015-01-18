#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char* argv[])
{
	char* str = NULL;
	char* tok = NULL;
	size_t strLen = 0;
	ssize_t readCount;

	readCount = getline(&str, &strLen, stdin);
	if (readCount == -1) {
		fprintf(stderr, "Error: read from stdin failed\n");
		exit(1);
	}

	tok = strtok(str, " ");
	while (tok) {
		printf("%s\n", tok);
		tok = strtok(NULL, " ");
	}

	free(str);
	str = NULL;
	strLen = 0;

	return 0;
}
