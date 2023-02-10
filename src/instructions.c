/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:45 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 17:13:51 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

t_inst	**add_x_instru(t_inst **instru, int i, int type, char stack)
{
	t_inst	*new;

	while (i)
	{
		new = instru_create_new(type, stack);
		if (!new)
			return (instru_clear(instru), NULL);
		instru_add_back(instru, new);
		i--;
	}
	return (instru);
}

t_inst	**move_to_top(t_stack *elem, t_infos inf, t_inst **inst, char stack)
{
	int	i;
	int	position;

	if (!elem)
		return (inst);
	else
		position = elem->pos;
	if (position > inf.size / 2 + inf.size % 2)
	{
		i = inf.size - position + 1;
		if (!add_x_instru(inst, i, REV_ROT, stack))
			return (NULL);
	}
	else
	{
		i = position - 1;
		if (!add_x_instru(inst, i, ROTATE, stack))
			return (NULL);
	}
	return (inst);
}

t_inst	**merge_duplicate_instru(t_inst **instru)
{
	t_inst	*cur1;
	t_inst	*cur2;
	int		stack1;

	if (!instru)
		return (NULL);
	cur1 = *instru;
	cur2 = *instru;
	stack1 = cur1->stack;
	while (cur2 && cur2->stack == stack1)
		cur2 = cur2->next;
	while (cur1 && cur2 && cur1->stack == stack1)
	{
		if (cur1->type == cur2->type)
		{
			cur1->type = cur1->type + 1;
			cur2->type = 0;
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return (instru);
}

int	get_instructions(t_stack *elem, t_infos *ib, t_stack **la, t_inst **inst)
{
	t_infos	ia;
	t_stack	*elem_sup;

	stack_update_infos(la, &ia);
	elem_sup = stack_get_elem_sup(la, ia, elem->nb);
	if (!move_to_top(elem, *ib, inst, B))
		return (-1);
	if (!move_to_top(elem_sup, ia, inst, A))
		return (-1);
	if (!add_x_instru(inst, 1, PUSH, A))
		return (-1);
	merge_duplicate_instru(inst);
	return (instru_get_size(inst));
}
