/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/06 18:37:33 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

/******************************************************************************/

typedef enum
{
    false,
    true
}       bool;

// idx est la ou est situe la valeur dans la stack
// pos est la ou doit etre situee la valeur apres le tri
typedef struct s_stack
{
    int                 content;
    int                 idx;
    int                 pos;
    int                 target;
    int                 cost_a;
    int                 cost_b;
    struct s_stack     *next;
}               t_stack;

/******************************************************************************/

/*  Instructions    */
void        sa(t_stack **a);
void        sb(t_stack **b);
void        ss(t_stack **a, t_stack **b);

void        ra(t_stack **a);
void        rb(t_stack **b);
void        rr(t_stack **a, t_stack **b);
void        do_rr(t_stack **a, t_stack **b, int *cost_b, int *cost_a);

void        rra(t_stack **a);
void        rrb(t_stack **b);
void        rrr(t_stack **a, t_stack **b);
void        do_rrr(t_stack **a, t_stack **b, int *cost_b, int *cost_a);

void        pa(t_stack **from_b, t_stack **to_a);
void        pb(t_stack **from_a, t_stack **to_b);

/*  Costs and Moves  */
void        setCost2move(t_stack **a, t_stack **b);
void        cheapestMove(t_stack **a, t_stack **b);

/*  Algorithm   */
// void     way2five(t_stack **a, t_stack **b);
void        sortMini(t_stack **a, t_stack **b);
void        sort(t_stack **a, t_stack **b);
bool        isSorted(t_stack *node);

/*  Stack handler   */
t_stack     *stackNew(int number);
t_stack     *getLast(t_stack *node);
t_stack     *getBeforeLast(t_stack *node);
void        addBottom(t_stack **stack, t_stack *new);

/*  Protection functions    */
void        clear(t_stack **stack);
void        isError(t_stack **a, t_stack **b);

/*  Util functions  */
int         stackSize(t_stack *node);
int         getMedian(t_stack *node);
t_stack     *findMin(t_stack *node);
int         findMinContent(t_stack *node);
// t_stack     *findMinAfterSet(t_stack *node);
t_stack     *findMax(t_stack *node);
int         getDistanceFromMin(t_stack **a, int min);

void        setIdx(t_stack **stack);
void        setPos(t_stack **stack);
int         setLowestIdx(t_stack **a);
void        getTarget(t_stack **b, t_stack **a);

/*  Check args and parse    */
bool        haveDuplicate(char **argv);
bool        globalCheckIsSuccess(char **argv);

t_stack     *ParseAndFill(char **argv);

#endif