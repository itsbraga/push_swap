/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/13 20:58:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bool	is_sign(char c)
{
	if (!(c == '-' || c == '+'))
		return (false);
	return (true);
}

static t_bool	is_space(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		return (false);
	return (true);
}

static t_bool	is_only_digit(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1])
		i++;
	else if (is_space(&str[i]) && str[i + 1])
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		return (false);
	return (true);
}

static t_bool	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && (nbr_in_str_cmp(argv[i], argv[j]) == 0))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

t_bool	global_check_successful(char **argv)
{
	int	i;

	i = 1;
	if (have_duplicates(argv) == true)
		return (false);
	while (argv[i])
	{
		if (!is_only_digit(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

// int	check_errors(char **argv, t_stack *a)
// {
// 	char	*str;

// 	str = NULL;
// 	if (have_duplicates(argv) == true)
// 		str = "Error: args have duplicates in it.\n";
// 	else if (is_only_int(*argv) == false)
// 		str = "Error: either your arguments are overflowing, \
// 		or they contain special characters.\n";
// 	else if (!a)
// 		str = "Error: stack_a could not be created.\n";
// 	else if (is_sorted(a))
// 		str = "Error: args are already sorted.\n";
// 	if (str)
// 		return (write(STDERR_FILENO, str, ft_strlen(str)));
// 	return (0);
// }
