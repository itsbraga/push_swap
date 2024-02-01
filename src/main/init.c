/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:49:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/01 23:48:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack     *ParseAndFill(char **argv)
{
    t_stack *a;
    int     i;
    long    nbr;

    a = NULL;
    i = 1;
    while (argv[i])
    {
        if (ft_strlen(argv[i]) > 11)
            return (isError(&a, NULL), NULL);
        nbr = ft_atol(argv[i]);
        if (nbr >= INT_MIN && nbr <= INT_MAX)
        {
            if (i == 1)
                a = stackNew((int)nbr);
            else
                addBottom(&a, stackNew((int)nbr));
        }
        else
            isError(&a, NULL);
        i++;
    }
    return (a);
}