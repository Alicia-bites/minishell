/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:20:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/13 15:47:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SEP_P "####################"

/*struct stat { */
/*    dev_t     st_dev;     *//* ID of device containing file */
/*    ino_t     st_ino;     *//* inode number */
/*    mode_t    st_mode;    *//* protection */
/*    nlink_t   st_nlink;   *//* number of hard links */
/*    uid_t     st_uid;     *//* user ID of owner */
/*    gid_t     st_gid;     *//* group ID of owner */
/*    dev_t     st_rdev;    *//* device ID (if special file) */
/*    off_t     st_size;    *//* total size, in bytes */
/*    blksize_t st_blksize; *//* blocksize for file system I/O */
/*    blkcnt_t  st_blocks;  *//* number of 512B blocks allocated */
/*    time_t    st_atime;   *//* time of last access */
/*    time_t    st_mtime;   *//* time of last modification */
/*    time_t    st_ctime;   *//* time of last status change */
/*}; */

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	int	i;
	int	res;
	struct stat	*buf;

	if (argc == 1)
		return (0);
	i = 1;
	res = 0;
	buf = NULL;
	while (i < argc)
	{
		buf = malloc(sizeof(struct stat));
		printf("argv[%d]: %s\n", i, argv[i]);
		res = lstat(argv[i], buf);
		printf("res: %d\tbuf: %p\n", res, buf);
		if (buf)
		{
			printf("st_dev: %lu\n", buf->st_dev);
			printf("st_size: %lu\n", buf->st_size);
		}
		free(buf);
		i++;
		printf("%s\n", SEP_P);
	}
	return (1);
}
