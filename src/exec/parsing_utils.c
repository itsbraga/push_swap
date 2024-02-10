/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:57:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/10 18:21:10 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	split_case(char **argv, t_stack *a)
{
	t_stack		*b;

	argv = ft_split(argv[1], ' ');
	a = parse_n_fill(argv);
	if (!a)
		(free_split(argv), is_error(&a, NULL));
	b = NULL;
	if (is_sorted(a) == true)
		clear(&a);
	else
		(set_pos(&a), push_swap(&a, &b), clear(&a), clear(&b));
	free_split(argv);
	return (EXIT_SUCCESS);
}

int nbr_in_str_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

    i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
