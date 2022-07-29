/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_message.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:19:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/29 14:35:42 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MESSAGE_H
# define MINISHELL_MESSAGE_H

// DEFAULT BASH MESSAGE
# define ERR_ARG_N "too many arguments"
# define ERR_ARG_NUM "numeric argument required"
# define ERR_CMD_FOUND "command not found"
# define ERR_ID_VAL "not a valid identifier"
# define ERR_NOHOME "HOME not set"
# define ERR_OPT_INVAL "invalid option"
# define ERR_TOK_BRACKET "syntax error near unexpected token"

// MINISHELL CUSTOMIZED MESSAGE
# define ERR_ECHO_FAILURE "echo has failed"
# define ERR_FORK "fork issue"
# define ERR_PFD "impossible to create a file descriptor"
# define ERR_PIPE "pipe issue"
# define ERR_PWD "impossible to get the current directory"
# define ERR_NOTOK "first no token address"
# define ERR_SIGACTION "setting up sigaction failed"

#endif
