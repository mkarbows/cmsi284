#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int64_t subtract(int64_t, int64_t);

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Please enter 3 arguments\n");
		return 0;
	}
	int firstArg = atoi(argv[1]);
	int secondArg = atoi(argv[2]);
	printf("%ld\n", subtract(firstArg, secondArg));
}
