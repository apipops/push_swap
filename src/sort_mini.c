/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:05 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 16:11:36 by avast            ###   ########.fr       */
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
		(stack_swap(lst), ft_printf("sa\n"));
	stack_update_infos(lst, infos);
}

void	sort_three(t_stack **lsta, t_infos *infosa)
{
	if (stack_check_order(lsta) == OK)
		return ;
	else if (infosa->min->pos == 1)
		(stack_swap(lsta), stack_rotate(lsta), ft_printf("sa\nra\n"));
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
				ft_printf("sa\nrra\n"));
		else
			(stack_rotate(lsta), ft_printf(RA));
	}
	stack_update_infos(lsta, infosa);
}

/* int	sort_five(t_stack **lsta, t_infos *infosa, t_stack	**lstb)
{
	int		i;
	int		count;
	t_inst	*ins;

	i = 0;
	count = infosa->size;
	ins = NULL;
	while (i < count - 3)
	{
		while (infosa->min->pos != 1)
		{
			if (infosa->min->pos > (infosa->size / 2 + infosa->size % 2))
				(stack_reverse_rotate(lsta), ft_printf(RRA));
			else
				(stack_rotate(lsta), ft_printf(RA));
			stack_update_infos(lsta, infosa);
		}
		(stack_push(lsta, lstb), ft_printf(PB));
		stack_update_infos(lsta, infosa);
		i++;
	}
	sort_three(lsta, infosa);
	(stack_push(lstb, lsta), ft_printf(PA));
	(stack_push(lstb, lsta), ft_printf(PA));
	stack_update_infos(lsta, infosa);
} */

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
		if (!add_x_instru(&ins, 1, PUSH, A))
			return (-1);
		instru_display(&ins);
		instru_clear(&ins);
		stack_update_infos(lsta, infosa);
		i++;
	}
	sort_three(lsta, infosa);
	(stack_push(lstb, lsta), ft_printf(PA));
	(stack_push(lstb, lsta), ft_printf(PA));
	stack_update_infos(lsta, infosa);
	return (0);
}
