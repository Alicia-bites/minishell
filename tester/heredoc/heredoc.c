#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int	fd;

	//fd = open("/home/smb_bouboule/42_minishell/tester/heredoc", O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR);
	//fd = open("/home/smb_bouboule/42_minishell/tester/heredoc/test.foo", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	fd = open("/tmp/test.foo", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		printf("fd issue\n");
		return (1);
	}
	close(fd);
	unlink("/tmp/test.foo");
	return (0);
}
