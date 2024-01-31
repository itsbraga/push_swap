/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/01 00:38:39 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_swap(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stackSize(*a);
	if (size_a == 2 && !isSorted(*a))
		sa(a);
	if ((size_a >= 3 && size_a <= 5) && !isSorted(*a))
		sortMini(a, b);
	else
		sort(a, b);
}

static void    printStack(t_stack *node, char c)
{
    t_stack *tmp;

    tmp = node;
    while (tmp != NULL)
    {
        ft_putnbr_fd(tmp->content, 1);
        ft_putendl_fd("", 1);
        tmp = tmp->next;
    }
    write(1, "\n-\n", 3);
    write(1, &c, 1);
    write(1, "\n\n", 2);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc == 1)
	{
		ft_printf(YELLOW BOLD "Oops! No values to sort.");
		ft_printf(YELLOW BOLD " Please, type some." RESET);
	}
	if (argc == 2)
		return (0);
	if (globalCheckIsSuccess(argv) == false)
		isError(NULL, NULL);
	b = NULL;
	a = ParseAndFill(argc, *argv);
	push_swap(&a, &b);
	ft_printf(PINK "STACK AFTER PUSH_SWAP SORT\n");
	printStack(a, 'a');
	clear(&a);
	clear(&b);
	return (0);
}