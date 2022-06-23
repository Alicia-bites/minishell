/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 19:39:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//clear the list starting from the LAST element
void	ft_lstclear_back(t_expanded **lst)
{
	t_expanded	*iterator;
	t_expanded	*prev;

	if (*lst == NULL)
		return ;
	iterator = *lst;
	prev = NULL;
	while (iterator->prev)
	{
		prev = iterator;
		iterator = iterator->prev;
		free(prev);
	}
	free(iterator);
	*lst = NULL;
}

void	print_dollar_lst(t_expanded *lst)
{
	t_expanded *iterator;

	iterator = lst;
	while (iterator)
	{
		printf("index = %d\n", iterator->index);
		printf("expanded = %s\n", iterator->expanded);
		puts("-----------------------------------------");
		iterator = iterator->next;		
	}
}
int is_varname(char c)
{
	if (ft_isalnum(c) || c == '_')
			return (1);
	return (0);
}

void	ft_lstadd_back_dollar(t_expanded **alst, t_expanded *new)
{
	t_expanded	*iterator;

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

t_expanded	*ft_lstnew_dollar(char *str, int i)
{
	t_expanded	*elt;

	elt = malloc(sizeof(t_expanded));
	if (!elt)
		return (NULL);
	elt->index = i;
	elt->expanded = str;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}

// Create a linked list of inputs with indexes
t_expanded	*create_dollar_list(char *str, int index)
{
	static t_expanded			*lst;
	t_expanded					*new;

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

	len = end - start;
	new_str = malloc(sizeof(char) * end + 1);
	if (!new_str)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return (NULL);
	}
	i = 0;
	while (i <= len - 1)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}

void	get_expanded(char *str, t_expanded **expanded_list, int i, int *varsize)
{
	extern	t_global	*g_global;
	static int	index = 0;
	int			j;
	char 		*var;
	char		*expanded;

	if (g_global->expansions_list_cleared)
	{
		index = 0;
		g_global->expansions_list_cleared = 0;
	}
	if (str[i + 1] == '0')
		*expanded_list = create_dollar_list("minishell", index++);
	else if (ft_isdigit(str[i + 1]))
		*expanded_list = create_dollar_list("", index++);
	else if (is_varname(str[i + 1]))
	{
		i++;
		j = i;
		while (is_varname(str[j]))
			j++;
		var = malloc_varname(str, i, j);
		*varsize = ft_strlen(var) + 1;
		expanded = getenv(var);
		if (!expanded)
		{
			printf("unknown variable\n");
			return ;			
		}
		*expanded_list = create_dollar_list(expanded, index++);
	}
}

int	get_full_size(t_expanded *expanded_list)
{
	t_expanded *it;
	int			length;

	it = expanded_list;
	length = 0;
	while (it)
	{
		length += ft_strlen(it->expanded);
		it = it->next;
	}
	return (length);
}

char	*insert_expansions(int full_size, t_expanded *expanded_list, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*new_str;

	new_str = malloc(sizeof(char) * full_size + 1);
	if (!new_str)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return (NULL);
	}
	ft_bzero(new_str, sizeof(char) * (full_size + 1));
	i = 0;
	j = 0;
	k = 0;
	while (i <= full_size)
	{
		if (str[k] == '$')
		{
			j = 0;
			while (j < ft_strlen(expanded_list->expanded))
				new_str[i++] = expanded_list->expanded[j++];
			expanded_list = expanded_list->next;
			k++;
			while (ft_isalnum(str[k]))
				k++;				
		}
		new_str[i++] = str[k++];
	}
	new_str[i] = '\0';
	return (new_str);
}

void	find_expansions(char *str, t_expanded **expanded_list, int *full_size)
{
	int			i;
	int			varsize;
	
	varsize = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			get_expanded(str, expanded_list, i, &varsize);
			*full_size -= varsize;
		}
		i++;
	}
}

char	*expand_dollar(char *str, t_chartype *input_list)
{
	extern	t_global	*g_global;
	char 		*new_str;
	int			full_size;
	t_expanded	*expanded_list;

	full_size = 0;
	if (!count_single(str) && !count_double(str))
		find_expansions(str, &expanded_list, &full_size);
	full_size += get_full_size(expanded_list) + ft_strlen(str);
	new_str = insert_expansions(full_size, expanded_list, str);
	ft_lstclear_back(&expanded_list);
	g_global->expansions_list_cleared = 1;
	return (new_str);
}

void	ft_parse(char *str, t_list **token_list)
{	
	t_chartype	*input_list;
	int			i;
	int			length;

	i = 0;
	length = 0;
	if (ft_strstr(str, "$"))
		str = expand_dollar(str, input_list);
	length = ft_strlen(str);
	input_list = malloc(sizeof(t_chartype) * (length + 1));
	if (!input_list)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return ;		
	}
	ft_bzero(input_list, sizeof(t_chartype) * (length + 1));
	count_quotes(str, input_list);
	while (i < length)
	{
		input_list[i].character = str[i];
		input_list[i].length = length;
		i++;
	}
	tokenize(input_list, token_list);
	print_lst(*token_list);
	// sort_input(input_list);
}
