/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:57:45 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 19:17:53 by avast            ###   ########.fr       */
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
	/* ft_printf("merged list :\n");
	instru_display(instru); */
	return (instru);
}

int	get_inst_from_a(t_stack *elem, t_infos *ia, t_stack **lb, t_inst **inst)
{
	t_infos	ib;
	t_stack	*elem_inf;

	ib = stack_get_infos(lb);
	elem_inf = stack_get_elem_inf(lb, ib, elem->nb);
	if (!move_to_top(elem, *ia, inst, A))
		return (-1);
	if (!move_to_top(elem_inf, ib, inst, B))
		return (-1);
	if (!add_x_instru(inst, 1, PUSH, B))
		return (-1);
	merge_duplicate_instru(inst);
	return (instru_get_size(inst));
}

int	get_inst_from_b(t_stack *elem, t_infos *ib, t_stack **la, t_inst **inst)
{
	t_infos	ia;
	t_stack	*elem_sup;

	(void)ib;
	ia = stack_get_infos(la);
	elem_sup = stack_get_elem_sup(la, ia, elem->nb);
/* 	if (!move_to_top(elem, *ib, inst, B))
		return (-1); */
	if (!move_to_top(elem_sup, ia, inst, A))
		return (-1);
	if (!add_x_instru(inst, 1, PUSH, A))
		return (-1);
	return (0);
}

int	get_inst_from_bb(t_stack *elem, t_infos *ib, t_stack **la, t_inst **inst)
{
	t_infos	ia;
	t_stack	*elem_sup;

	ia = stack_get_infos(la);
	elem_sup = stack_get_elem_sup(la, ia, elem->nb);
	if (!move_to_top(elem, *ib, inst, B))
		return (-1);
	if (!move_to_top(elem_sup, ia, inst, A))
		return (-1);
	if (!add_x_instru(inst, 1, PUSH, A))
		return (-1);
	return (0);
}

/*
t_inst	**get_instru_a(t_stack *elem, t_infos *infosa, t_inst **instru)
{
	int			i;

	if (elem->pos > infosa->size / 2 + infosa->size % 2)
	{
		i = infosa->size - elem->pos + 1;
		if (!add_x_instru(instru, i, REV_ROT, A))
			return (NULL);
	}
	else
	{
		i = elem->pos - 1;
		if (!add_x_instru(instru, i, ROTATE, A))
			return (NULL);
	}
	return (instru);
}

t_inst	**get_instru_b(t_stack *elem, t_stack **lstb, t_inst **instru)
{
	t_infos		infosb;
	int			position;
	int			i;
	t_inst		*push;

	infosb = stack_get_infos(lstb);
	position = stack_get_position_inf(lstb, infosb, elem->nb);
	if (position > infosb.size / 2 + infosb.size % 2)
	{
		i = infosb.size - position + 1;
		if (!add_x_instru(instru, i, REV_ROT, B))
			return (NULL);
	}
	else
	{
		i = position - 1;
		if (!add_x_instru(instru, i, ROTATE, B))
			return (NULL);
	}
	push = instru_create_new(PUSH, B);
	if (!push)
		return (instru_clear(instru), NULL);
	instru_add_back(instru, push);
	return (instru);
}

int	get_instrus(t_stack *ele, t_infos *ia, t_stack **lb, t_inst **instru)
{
	t_inst	*instrub;
	t_inst	*cura;
	t_inst	*curb;

	instrub = NULL;
	if (!get_instru_a(ele, ia, instru) || !get_instru_b(ele, lb, &instrub))
		return (0);
	cura = *instru;
	curb = instrub;
	while (cura && curb)
	{
		if (cura->type == curb->type)
		{
			cura->type = cura->type + 1;
			curb->type = 0;
			curb = curb->next;
		}
		cura = cura->next;
	}
	instru_add_back(instru, instrub);
	return (instru_get_size(instru));
}
 */