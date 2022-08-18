/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:45:06 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:16:40 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MESSAGE_H
# define FT_MESSAGE_H

# include <string.h>
# include <errno.h>
# include "ft_put.h"

/***GLOBAL***/
# define SEP_P "******************************"
# define SEP_S "------------------------------"
# define ERR_ARG "Wrong argument definition"
# define ERR_FILEOPEN "File is missing or not readable"
# define ERR_MALLOC "Malloc issue"
# define ERR_NOOBJ "No object address"

/***FILE DESCRIPTOR***/
# define ERR_FD "File descriptor not defined"

/***LIST***/
# define ERR_NOLIST "No list address"
# define ERR_LST_APPEND "Error on append list"

/**STRING***/
# define ERR_MAXLEN_INT "Length string is more than MAX_LEN_INT"

int		ft_panic(int errcode, const char *filename, char *msg);
void	*ft_panic_null(int errcode, const char *filename, char *msg);
int		ft_panic_value(int errcode, const char *filename, char *msg,
			int value);
int		ft_shell_msg(int errcode, char *data);
int		ft_putchar_fd_const(const char c, int fd);
int		ft_putendl_fd_const(const char *s, int fd);
int		ft_putstr_fd_const(const char *s, int fd);

#endif
