/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:17:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 18:41:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include "ft_message.h"
# include "ft_string.h"

typedef enum e_toktype {
	TOK_UNKNOWN,
	TOK_BUILTIN,
	TOK_SPACE,
	TOK_CMD,
	TOK_ARG,
	TOK_PIPE,
	TOK_SQUOTE,
	TOK_DQUOTE,
	TOK_ENV_NAME,
	TOK_ENV_CALL,
	TOK_L_REDIR,
	TOK_R_REDIR,
	TOK_DL_REDIR,
	TOK_DR_REDIR,
	TOK_BN,
	TOK_FILE,
	TOK_HERESEP,
	TOK_NOT_OP,
}	t_toktype;

typedef struct s_ulist
{
	void			*content;
	struct s_ulist	*prev;
	struct s_ulist	*next;
}			t_ulist;

typedef struct s_list
{
	int				index;
	t_toktype		toktype;
	char			*token;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

t_ulist	*ft_lst_append(t_ulist **lst, void *content);
void	ft_lst_clear(t_ulist **lst, void (*f)(void *));
t_ulist	*ft_lst_delbyobj(t_ulist *obj, void (*f)(void *));
void	ft_lst_free(t_ulist **list, void (*f)(void *));
void	ft_lst_func_lst(t_ulist **list, void (*f)(void *));
t_ulist	**ft_lst_init(void);
t_ulist	*ft_lst_last(t_ulist *lst);
t_ulist	*ft_lst_new(void *content);
size_t	ft_lst_size(t_ulist **lst);

t_list	*ft_lstnew(char *str, int i, t_toktype toktype);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lst_delnode(t_list *obj, void (*f)(t_list *));

#endif
