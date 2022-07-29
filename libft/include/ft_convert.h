/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:13:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/27 11:13:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include <stdlib.h>
# include "ft_chartype.h"

int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);
char				*ft_itoa(int n);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
