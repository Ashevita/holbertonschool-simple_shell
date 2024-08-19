#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t n = 10;
	char *buf;

	buf = malloc(sizeof(char) * 10);
	printf ("Enter your name");
	getline("&buf");
}
