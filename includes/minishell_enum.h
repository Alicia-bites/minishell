/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_enum.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:22:31 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/14 09:54:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENUM_H
# define MINISHELL_ENUM_H

typedef enum e_chartype {
	CH_UNKNOWN,
	CH_WORD,
	CH_SPACE,
	CH_PIPE,
	CH_S_QUOTE,
	CH_D_QUOTE,
	CH_DOLLAR,
	CH_L_REDIR,
	CH_R_REDIR,
	CH_EQUAL,
	CH_INTPOINT,
	CH_BN,
}	t_enum_chartype;

typedef enum e_fd_access
{
	ACCESS_UNDEFINED,
	ACCESS_X,
	ACCESS_W,
	ACCESS_R
}	t_fd_access;

typedef enum e_redir_open
{
	DIR_IN,
	DIR_OUT
}	t_redir_open;

typedef enum e_var_view
{
	VAR_ALL,
	VAR_ENV,
	VAR_EXP
}	t_var_view;

typedef enum e_hd_mode
{
	HD_NO_EXP,
	HD_EXP
}	t_hd_mode;

#endif
