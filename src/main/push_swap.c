/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/01/29 20:43:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_swap(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = stackSize(*a);
	if (a_size == 2 && !isSorted(*a))
		sa(a);
	if ((a_size >= 3 && a_size <= 5) && !isSorted(*a))
		sortMini(a);
	else
		sortBig(a, b);
}

static void    printStack(t_stack *node, char c)
{
    t_stack *tmp;

    tmp = node;
    while (tmp != NULL)
    {
        ft_putnbr_fd(tmp->value, 1);
        ft_putendl_fd("", 1);
        tmp = tmp->next;
    }
    write(1, "\n-\n", 3);
    write(1, &c, 1);
    write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc < 2)
		return (0);
	if (globalCheck(argv) == false)
		isError(NULL, NULL);
	b = NULL;
	a = init_a(argc, argv);
	printStack(a, 'a');
	push_swap(&a, &b);
	printStack(a, 'a');
	clear(&a);
	clear(&b);
	return (0);
}