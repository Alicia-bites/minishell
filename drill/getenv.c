#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("%s\n", getenv("PATH"));
	printf("%s\n", getenv("USER"));
	printf("%s\n", getenv("ALICIA"));
	return (0);
}

