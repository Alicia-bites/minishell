#include <signal.h>
#include <stdio.h>

void handle(int signo)
{
	printf("Recu signal : %d\n", signo);
}

int main(void) {
	for (;;) {}
}
