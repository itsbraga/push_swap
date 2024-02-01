/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/01 23:48:15 by annabrag         ###   ########.fr       */
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

static void    showStack(t_stack *node, char c)
{
    t_stack		*tmp;
    unsigned int	idx;

    if (!node)
	return ;
    tmp = node;
    idx = 0;
    write(1, "\n", 1);
    while (tmp)
    {
	ft_printf("Stack (%d) ➔	  %d\n", idx++, tmp->content);
        tmp = tmp->next;
    }
    ft_printf("		  —\n");
    ft_printf("		  %c\n\n", c);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	if (argc < 2)
	{
		ft_printf(YELLOW BOLD "Too few arguments to use ./push_swap\n");
		return (EXIT_FAILURE);
	}
	a = ParseAndFill(argv);
	if (!a)
		isError(NULL, NULL);
	if (globalCheckIsSuccess(argv) == false)
		isError(NULL, NULL);
	b = NULL;
	setPos(&a);
	push_swap(&a, &b);
	showStack(a, 'A');
	showStack(b, 'B');
	clear(&a);
	clear(&b);
	return (EXIT_SUCCESS);
}