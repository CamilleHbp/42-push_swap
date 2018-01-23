/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:16:15 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/23 15:10:50 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Un second nommé push_swap qui calcule et affiche sur la sortie standard le
** plus petit programme dans le langage des instructions de Push_swap qui trie
** les entiers passés en paramètre.
*/

#include "push_swap.h"

static void	print_output(int32_t *cmd)
{
	while (*cmd)
	{
		if (*cmd == SA)
			ft_putstr("sa\n");
		else if (*cmd == SB)
			ft_putstr("sb\n");
		else if (*cmd == SS)
			ft_putstr("ss\n");
		else if (*cmd == PA)
			ft_putstr("pa\n");
		else if (*cmd == PB)
			ft_putstr("pb\n");
		else if (*cmd == RA)
			ft_putstr("ra\n");
		else if (*cmd == RB)
			ft_putstr("rb\n");
		else if (*cmd == RR)
			ft_putstr("rr\n");
		else if (*cmd == RRA)
			ft_putstr("rra\n");
		else if (*cmd == RRB)
			ft_putstr("rrb\n");
		else if (*cmd == RRR)
			ft_putstr("rrr\n");
		++cmd;
	}
}

void	select_algorithm(int8_t choice, t_stack stack_a, t_stack stack_b)
{

}

int	main (int ac, char **av)
{
	t_cmd	*instructions;
	int32_t	status;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (SUCCESS);
	else if (ac == 2)
		stack_a = get_element_string(&av[1]);
	else
		stack_a = return_stack(ac - 1, &av[1]);
	if (stack_a == NULL)
	{
		ft_putstr("Error\n");
		return (SUCCESS);
	}
	stack_b = init_stack(0);
	instructions = init_instructions();
	instructions = insertion_sort(*stack_a, *stack_b);
	print_output(instructions);
	free(instructions);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (SUCCESS);
}
