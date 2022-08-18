/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_message.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:19:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:55:01 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MESSAGE_H
# define MINISHELL_MESSAGE_H

// DEFAULT BASH MESSAGE
# define ERR_ARG_N "too many arguments"
# define ERR_ARG_NUM "numeric argument required"
# define ERR_CMD_FOUND "command not found"
# define ERR_COREDUMP "Quit (core dumped)"
# define ERR_FD_OVER "too many open files"
# define ERR_HD_ISSUE "impossible to create a temporary file for here-document"
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
# define ERR_TOK_REDIR "no file after redirection"
# define ERR_TOK_HERESEP "no heredoc separator after redirection"

# define MSGERR_QUOTE "smbash: syntax error. Please check quotes."
# define MSGERR_PIPE "smbash: syntax error. Please check pipes."
# define MSGERR_REDIR "smbash: syntax error. Please check redirections."
# define MSGERR_BRACKETS "smbash: syntax error. Please check brackets."
# define MSGERR_SPACE "smbash: syntax error. Please check pipes."
# define MSGERR_SYM "smbash: syntax error. Put special char between quotes."
# define MSGERR_DOLLAR "smbash: syntax error. Please check dollar."
# define MSGERR_ONLY_SPACE "smbash: syntax error. No command before pipe."
# define MSGERR_SIGCATCH "Program encountered segmentation fault."

#endif
