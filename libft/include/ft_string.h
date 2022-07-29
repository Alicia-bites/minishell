/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:41:10 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/28 12:53:32 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

# define STR_LONG_LONG_MAX "9223372036854775807"
# define STR_LONG_LONG_MIN "9223372036854775808"

void	ft_bzero(void *s, size_t n);
int		ft_index(const char *s, int c);
void	ft_left_strip(char *s);
void	ft_right_strip(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strchrset_include(const char *s, const char *chrset);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
void	ft_strip(char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);
size_t	ft_strstrlen(char **str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_str_isll(char *str);
int		ft_str_isdigit(char *str);
char	*ft_strnchr(const char *s, int c, size_t n);

#endif
