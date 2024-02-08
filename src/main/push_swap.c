/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:28:28 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/08 21:57:07 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static void	push_swap(t_stack **a, t_stack **b)
{
	int	size_a;
	
	size_a = stackSize(*a);
	if (!isSorted(*a))
	{
		if (size_a == 2)
			sa(a);
		if (size_a >= 3 && size_a <= 5)
			sortMini(a, b);
		if (size_a > 5)
			sort(a, b);
		showStack(*a, 'A');
		showStack(*b, 'B');
		clear(a);
		clear(b);
	}
	return ;
}

static int	splitCase(char **argv, t_stack *a)
{
	t_stack	*b;
	int	i;

	i = -1;
	argv = ft_split(argv[1], ' ');
	if (globalCheckIsSuccess(argv) == true)
	{
		// argv = ft_split(argv[1], ' ');
		a = ParseAndFill(argv);
		if (!a)
			isError(&a, NULL);
		b = NULL;
		(setPos(&a), push_swap(&a, &b));
		while (argv[++i])
			free(argv[i]);
		free(argv);
		return (EXIT_SUCCESS);
	}
	while (argv[++i])
		free(argv[i]);
	free(argv);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;
	
	a = NULL;
	i = -1;
	if (argc < 2)
		return (ft_printf(YELLOW "Too few arguments to use this program\n",
				EXIT_FAILURE));
	if (argc == 2)
	{
		if (splitCase(argv, a) == 1)
			isError(&a, NULL);
		return (EXIT_SUCCESS);
	}
	else if (globalCheckIsSuccess(argv) == true)
	{
		a = ParseAndFill(argv);
		if (!a)
			isError(&a, NULL);
		b = NULL;
		(setPos(&a), push_swap(&a, &b));
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
