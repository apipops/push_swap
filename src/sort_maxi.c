/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_maxi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:01:57 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 16:58:26 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

int	sort_maxi(t_stack **la, t_infos *ia, t_stack **lb, t_infos *ib)
{
	t_inst		*instru;
	t_inst		*final_instru;

	instru = NULL;
	final_instru = NULL;
	push_to_b(la, ia, lb, ib);
	sort_three(la, ia);
	while (*lb)
	{
		if (push_to_a(la, *lb, ib, &instru) == -1)
			return (-1);
		(instru_display(&instru), instru_exec(&instru, la, lb));
		(instru_clear(&instru), stack_update_infos(lb, ib));
	}
	stack_update_infos(la, ia);
	if (!move_to_top(ia->min, *ia, &final_instru, A))
		return (-1);
	instru_exec(&final_instru, la, lb);
	instru_display(&final_instru);
	instru_clear(&final_instru);
	return (0);
}

void	push_to_b(t_stack **la, t_infos *ia, t_stack **lb, t_infos *ib)
{
	t_median	med;

	med = get_median(la, ia);
	while (med.count)
	{
		if ((*la)->nb <= med.val)
		{
			(stack_push(la, lb), ft_printf(PB));
			med.count--;
		}
		else
			(stack_rotate(la), ft_printf(RA));
	}
	while (ia->size > 3)
	{
		(stack_push(la, lb), ft_printf(PB));
		stack_update_infos(la, ia);
	}
	stack_update_infos(lb, ib);
}

int	push_to_a(t_stack **la, t_stack *elemb, t_infos *ib, t_inst **inst)
{
	t_inst	*tmp;
	int		cost;
	int		new_cost;

	*inst = NULL;
	tmp = NULL;
	cost = get_instru(elemb, ib, la, inst);
	if (cost == -1)
		return (-1);
	while (elemb)
	{
		new_cost = get_instru(elemb, ib, la, &tmp);
		if (new_cost == -1)
			return (instru_clear(inst), -1);
		if (new_cost < cost)
		{
			(instru_clear(inst), instru_clear(&tmp));
			cost = get_instru(elemb, ib, la, inst);
			if (cost == -1)
				return (-1);
		}
		instru_clear(&tmp);
		elemb = elemb->next;
	}
	return (0);
}
