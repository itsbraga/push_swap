/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:49:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/29 20:40:02 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack     *init_a(int argc, char **argv)
{
    t_stack *a;
    long     nb;
    int     i;

    a = NULL;
    nb = 0;
    i = 1;
    while (i < argc)
    {
        if (ft_strlen(argv[i]) > 11)
            isError(&a, NULL);
        nb = ft_atol(argv[i]);
        if (nb >= INT_MIN && nb <= INT_MAX)
        {
            if (i == 1)
                a = stackNew((int)nb);
            else
                addBottom(&a, stackNew((int)nb));
        }
        else
            isError(&a, NULL);
        i++;
    }
    return (a);
}