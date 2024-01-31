/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:49:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/01 00:10:12 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack     *ParseAndFill(int argc, char *argv)
{
    char    **args;
    t_stack *a;
    int     i;

    args = ft_split(argv, ' ');
    if (!args)
        return (NULL);
    a = NULL;
    i = 1;
    while (i < argc)
    {
        if (ft_strlen(args[i]) > 11)
            return (write(2, "Error\n", 6), exit(1), NULL);
        if (ft_atol(args[i]) >= INT_MIN && ft_atol(args[i]) <= INT_MAX)
        {
            if (i == 1)
                a = stackNew((int)ft_atol(args[i]));
            else
                addBottom(&a, stackNew((int)ft_atol(args[i])));
        }
        else
            isError(&a, NULL);
        i++;
    }
    return (a);
}