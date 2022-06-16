#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


int main(void)
{
	while (0x6969)
	{
		char *str = readline("prompt: ");
		printf("%s\n", str);
		add_history(str);
	}
}
