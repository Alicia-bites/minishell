/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:04:38 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/28 11:57:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h> 
# include <stdlib.h>
# include <unistd.h>

# include "ft_chartype.h"
# include "ft_convert.h"
# include "ft_list.h"
# include "ft_memory.h"
# include "ft_message.h"
# include "ft_put.h"
# include "ft_string.h"

//typedef enum e_toktype {
//	TOK_UNKNOWN,
//	TOK_WORD,
//	TOK_SPACE,
//	TOK_PIPE,
//	TOK_SQUOTE,
//	TOK_DQUOTE,
//	TOK_ENV_NAME,
//	TOK_ENV_CALL,
//	TOK_L_REDIR,
//	TOK_R_REDIR,
//	TOK_DL_REDIR,
//	TOK_DR_REDIR,
//	TOK_BN,
//} e_toktype;
//
//typedef struct s_list
//{
//	int				index;
//	e_toktype		toktype;
//	char			*token;
//	struct s_list	*prev;
//	struct s_list	*next;
//}	t_list;

//void	*ft_memset(void *dest, int c, size_t n);
//void	ft_bzero(void *s, size_t n);
//void	*ft_memcpy(void *s1, const void *s2, size_t n);
//void	*ft_memmove(void *dest, const void *src, size_t n);
//void	*ft_memchr(const void *b, int c, size_t n);
//int		ft_memcmp(const void *b1, const void *b2, size_t n);
//int		ft_strlen(const char *s);
//int		ft_strcmp(const char *s1, const char *s2);
//size_t	ft_strlcpy(char *dest, const char *src, size_t size);
//size_t	ft_strlcat(char *dest, const char *src, size_t size);
//char	*ft_strchr(const char *s, int c);
//char	*ft_strrchr(const char *s, int c);
//char	*ft_strstr(const char *big, const char *little);
//char	*ft_strnstr(const char *big, const char *little, size_t len);
//int		ft_strcmp(const char *s1, const char *s2);
//int		ft_strncmp(const char *s1, const char *s2, size_t n);
//int		ft_atoi(const char *str);
//int		ft_isalpha(int c);
//int		ft_isdigit(int c);
//int		ft_isalnum(int c);
//int		ft_isascii(int c);
//int		ft_isprint(int c);
//int		ft_toupper(int c);
//int		ft_tolower(int c);
//void	*ft_calloc(size_t nmemb, size_t size);
//char	*ft_strdup(const char *str);
//
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//char	*ft_strjoin(char const *s1, char const *s2);
//char	*ft_strtrim(char const *s1, char const *set);
//char	**ft_split(char const *s, char c);
//char	*ft_itoa(int n);
//char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//void	ft_putchar_fd(char c, int fd);
//void	ft_putstr_fd(char *s, int fd);
//void	ft_putendl_fd(char *s, int fd);
//void	ft_putnbr_fd(int n, int fd);
//int		isinteger(char *s);
//void		ft_strip(char *s);
//void		ft_rstrip(char *s);
//void		ft_lstrip(char *s);
//long long	ft_atoll(const char *str);
//int			ft_isspace(int c);


//t_list	*ft_lstnew(char *str, int i, e_toktype toktype);
//void	ft_lstadd_front(t_list **alst, t_list *new);
//int		ft_lstsize(t_list *lst);
//t_list	*ft_lstlast(t_list *lst);
//void	ft_lstadd_back(t_list **alst, t_list *new);
//void	ft_lstdelone(t_list *lst, void (*del)(void*));
//void	ft_lstclear(t_list **lst);
//void	ft_lstiter(t_list *lst, void (*f)(void *));
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif