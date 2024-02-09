/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:49:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/09 23:18:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*parse_n_fill(char **argv)
{
	t_stack		*a;
	int			i;
	int			error;
	long		nbr;

	a = NULL;
	i = 0;
	error = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i], &error);
		if (error == 1)
			break ;
		if (nbr >= INT_MIN && nbr <= INT_MAX)
		{
			if (i == 0)
				a = stack_new((int)nbr);
			else
				add2bottom(&a, stack_new((int)nbr));
		}
		else
			is_error(&a, NULL);
		i++;
	}
	return (a);
}
