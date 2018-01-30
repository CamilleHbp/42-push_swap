/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:44:30 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/30 15:07:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

/* void	append_instructions(t_cmd *original, t_cmd *to_append)
{
	int32_t	i;

	if (original == NULL
			|| (original->count % MAX_CMD) + to_append->count > MAX_CMD)
	{
		if ((original->cmd_array = ft_realloc(original->cmd_array,
				original->count * sizeof(int32_t),
				original->count * sizeof(int32_t) + MAX_CMD)) == NULL)
			return (ERROR);
	}
	i = original->count;
	while (i < to_append->count)
	{
		original->cmd_array[i] = to_append->cmd_array[i];
		++(original->count);
	}
} */

void	exec_command(int32_t cmd, t_stack *stack)
{
	if (cmd == SA)
		swap_a(stack);
	else if (cmd == SB)
		swap_b(stack);
	else if (cmd == SS)
		swap_ab(stack);
	else if (cmd == PA)
		push_a(stack);
	else if (cmd == PB)
		push_b(stack);
	else if (cmd == RA)
		rotate_a(stack);
	else if (cmd == RB)
		rotate_b(stack);
	else if (cmd == RR)
		rotate_ab(stack);
	else if (cmd == RRA)
		rev_rotate_a(stack);
	else if (cmd == RRB)
		rev_rotate_b(stack);
	else if (cmd == RRR)
		rev_rotate_ab(stack);
}

void	exec_instructions(t_cmd cmds, t_stack *stack)
{
	int32_t i;

	i = 0;
	while (i < cmds.count)
	{
		exec_command(cmds.cmd_array[i], stack);
		++i;
	}
}

int32_t	add_cmd_to_instructions(int32_t cmd, t_cmd *cmds)
{
	static int64_t	i = 0;

	if (cmds->cmd_array == NULL)
	{
		i = 0;
		if ((cmds->cmd_array = (int32_t*)malloc(sizeof(int32_t) * MAX_CMD)) == NULL)
			return (ERROR);
	}
	else if (!(i % (MAX_CMD / sizeof(int32_t) - 1)))
		if ((cmds->cmd_array = ft_realloc(cmds->cmd_array, i * sizeof(int32_t),
					i * sizeof(int32_t) + MAX_CMD)) == NULL)
			return (ERROR);
	cmds->cmd_array[i++] = cmd;
	++(cmds->count);
	return (SUCCESS);
}

void	free_instructions(t_cmd *cmds)
{
	free(cmds->cmd_array);
	free(cmds);
}

t_cmd	*init_instructions(void)
{
	t_cmd	*cmds;

	if ((cmds = (t_cmd*)malloc(sizeof(t_cmd))) == NULL)
		return (NULL);
	cmds->cmd_array = NULL;
	cmds->count = 0;
	return (cmds);
}
