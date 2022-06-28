/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:45:06 by abarrier          #+#    #+#             */
/*   Updated: 2022/06/28 12:41:21 by abarrier         ###   ########.fr       */
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

void	ft_panic(int errcode, char *msg);

#endif
