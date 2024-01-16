/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:49:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/16 22:26:29 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *init_a(int argc, char **argv)
{
    t_stack *a;
    int     nb;
    int     i;

    a = NULL;
    nb = 0;
    i = 1;
    while (i < argc)
    {
        nb = ft_atoi(argv[i]);
        if (nb > INT_MIN && nb < INT_MAX)
        {
            if (i == 1)
                a = ft_stackNew(nb);
            else
                ft_addbottom(a, ft_stackNew(nb));
        }
        else
            is_error(a, NULL);
    }
}