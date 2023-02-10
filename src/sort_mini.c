/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:05 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 16:11:47 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

void	sort_two(t_stack **lst, t_infos *infos)
{
	if (infos->min->pos == 1)
		return ;
	else
		(stack_swap(lst), ft_printf(SA));
	stack_update_infos(lst, infos);
}

void	sort_three(t_stack **lsta, t_infos *infosa)
{
	if (stack_check_order(lsta) == OK)
		return ;
	else if (infosa->min->pos == 1)
		(stack_swap(lsta), stack_rotate(lsta), ft_printf(SARA));
	else if (infosa->min->pos == 2)
	{
		if (infosa->max->pos == 1)
			(stack_rotate(lsta), ft_printf(RA));
		else
			(stack_swap(lsta), ft_printf(SA));
	}
	else if (infosa->min->pos == 3)
	{
		if (infosa->max->pos == 1)
			(stack_swap(lsta), stack_reverse_rotate(lsta),
				ft_printf(SARRA));
		else
			(stack_reverse_rotate(lsta), ft_printf(RRA));
	}
	stack_update_infos(lsta, infosa);
}

int	sort_five(t_stack **lsta, t_infos *infosa, t_stack	**lstb)
{
	int		i;
	int		count;
	t_inst	*ins;

	i = 0;
	count = infosa->size;
	ins = NULL;
	while (i < count - 3)
	{
		if (!move_to_top(infosa->min, *infosa, &ins, A))
			return (-1);
		if (!add_x_instru(&ins, 1, PUSH, B))
			return (-1);
		(instru_display(&ins), instru_exec(&ins, lsta, lstb));
		instru_clear(&ins);
		stack_update_infos(lsta, infosa);
		i++;
	}
	sort_three(lsta, infosa);
	(stack_push(lstb, lsta), ft_printf(PA));
	if (*lstb)
		(stack_push(lstb, lsta), ft_printf(PA));
	stack_update_infos(lsta, infosa);
	return (0);
}
