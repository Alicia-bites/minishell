/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 14:25:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int is_varname(char c)
{
	if (ft_isalnum(c) || c == '_')
			return (1);
	return (0);
}

void	ft_lstadd_back_dollar(t_list **alst, t_list *new)
{
	t_list	*iterator;

	iterator = *alst;
	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else
		{	
			while (iterator->next)
				iterator = iterator->next;
			iterator->next = new;
		}
	}
}

t_list	*ft_lstnew_dollar(char *str, int i)
{
	t_list	*elt;

	elt = malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->index = i;
	elt->token = str;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}

// Create a linked list of inputs with indexes
t_list	*create_dollar_list(char *str, int index)
{
	static t_list			*lst;
	t_list					*new;

	if (index == 0)
		lst = ft_lstnew_dollar(str, index);
	else
	{
		new = ft_lstnew_dollar(str, index);
		ft_lstadd_back_dollar(&lst, new);
	}
	return (lst);
}

char	*malloc_varname(char *str, int start, int end)
{
	char	*new_str;
	int		i;
	int		len;

	printf("start = %d\n", start);
	printf("end = %d\n", end);
	len = end - start;
	new_str = malloc(sizeof(char) * end + 1);
	if (!new_str)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return (NULL);
	}
	i = 0;
	while (i <= len - 1)
	{
		new_str[i] = str[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	printf("new_str = %s\n", new_str);
	return (new_str);
}

void	get_expanded(char *str, t_list **dollar_list, int i)
{
	static int	index = 0;
	int			j;
	char 		*var;
	
	if (str[i + 1] == '0')
		*dollar_list = create_dollar_list("minishell", index++);
	else if (ft_isdigit(str[i + 1]))
		*dollar_list = create_dollar_list("", index++);
	else if (is_varname(str[i + 1]))
	{
		i++;
		j = i;
		printf("i = %d\n", i);
		while (is_varname(str[j]))
		{
			j++;
		}
		printf("j = %d\n", j);
		var = malloc_varname(str, i, j);
	}
}

char	*expand_dollar(char *str, t_chartype *input_list)
{
	char	*loc;
	int		i;
	t_list	*dollar_list;

	if (!count_single(str) && !count_double(str))
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '$')
			{
				get_expanded(str, &dollar_list, i);
			}
			i++;
		}
	}
	return (str);
}

void	ft_parse(char *str, t_list **token_list)
{	
	t_chartype	*input_list;
	int			i;
	int			length;

	i = 0;
	if (ft_strstr(str, "$"))
		str = expand_dollar(str, input_list);
	length = ft_strlen(str);
	input_list = malloc(sizeof(t_chartype) * (length + 1));
	if (!input_list)
		return ;
	ft_bzero(input_list, sizeof(t_chartype) * (length + 1));
	count_quotes(str, input_list);
	while (i < length)
	{
		input_list[i].character = str[i];
		input_list[i].length = length;
		i++;
	}
	//FOR DEBUG
	// while (i != -1)
	// {
	// 	printf("%c", input_list[i].character);
	// 	i--;
	// }
	//END
	tokenize(input_list, token_list);
	// print_lst(token_list);
	// sort_input(input_list);
}
