/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_maxi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:01:57 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 15:26:38 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

int	sort_maxi(t_stack **la, t_infos *ia, t_stack **lb, t_infos *ib)
{
	t_inst		*final_order; 

	if (push_to_lb(la, ia, lb, ib) == -1)
		return (-1);
	sort_three(la, ia);
/* 	if (push_back_to_la_1(la, ib, lb, median) == -1)
		return (-1); 
	stack_update_infos(la, ia); */
	if (push_back_to_la_2(la, ib, lb) == -1)
		return (-1); 
	stack_update_infos(la, ia);
 	final_order = NULL;
	if (!move_to_top(ia->min, *ia, &final_order, A))
		return (-1);
	instru_exec(&final_order, la, lb);
	instru_display(&final_order);
	instru_clear(&final_order);
	stack_update_infos(la, ia);  
	return (0);
}

/* t_stack	**get_already_sort(t_stack **la, t_infos *ia, t_stack **sort)
{
	t_stack	*sorted;
	t_stack	*cur;
	int		size;

	sorted = stack_dup_elem(ia->min);
	if (!sorted)
		return (NULL);
	stack_add_back(sort, sorted);
	cur = ia->min;
	size = ia->size;
	while (cur)
	{
		if (cur == stack_get_elem_sup(la, *ia, sorted->nb))
		{
			sorted = stack_dup_elem(stack_get_elem_sup(la, *ia, sorted->nb));
			if (!sorted)
				return (NULL);
			stack_add_back(sort, sorted);
		}
		cur = cur->next;
		size--;
	}
 	ft_printf("==>ALREADY SORT:\n");
	stack_display(sort); 
	return (sort);
} */

/* t_stack	**get_already_sort(t_stack **la, t_infos ia, t_stack **sort)
{
	t_stack	*sorted;
	t_stack *inf;

	sorted = stack_dup_elem(ia.max);
	if (!sorted)
		return (NULL);
	stack_add_back_no_pos(sort, sorted);
	inf = stack_get_elem_inf(la, ia, sorted->nb);
	while (inf && inf->pos < sorted->pos)
	{
		sorted = stack_dup_elem(inf);
		inf = stack_get_elem_inf(la, ia, inf->nb);
		if (!sorted)
			return (NULL);
		stack_add_back_no_pos(sort, sorted);
	}
 	ft_printf("==>ALREADY SORT:\n");
	stack_display(sort);  
	return (sort);
} */

int	push_to_lb(t_stack **la, t_infos *ia, t_stack **lb, t_infos *ib)
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
	return (0);
}

int	push_back_to_la_1(t_stack **la, t_infos *ib, t_stack **lb, t_median med)
{
	t_stack		*cur;
	t_inst		*inst;
	t_inst		*tmp;
	int			cost;

	while (med.count)
	{
		cur = *lb;
		inst = NULL;
		tmp = NULL;
		cost = get_inst_from_bb(get_first_abo_med(lb, med.val), ib, la, &inst);
		while (cur)
		{
			if (cur->nb > med.val && get_inst_from_bb(cur, ib, la, &tmp) < cost)
			{
				(instru_clear(&inst), instru_clear(&tmp));
				cost = get_inst_from_bb(cur, ib, la, &inst);
			}
			instru_clear(&tmp);
			cur = cur->next;
		}
/*    		(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb), instru_display(&inst));
		ft_printf("==> INSTRUCTIONS :\n");   */
		(instru_display(&inst), instru_exec(&inst, la, lb));
		(instru_clear(&inst), instru_clear(&tmp), stack_update_infos(lb, ib));
		med.count--;
	}
	return (0);
}

int	push_back_to_la_2(t_stack **la, t_infos *ib, t_stack **lb)
{
	t_stack		*cur;
	t_inst		*inst;
	t_inst		*tmp;
	int			cost;

	while (ib->size)
	{
		cur = *lb;
		inst = NULL;
		tmp = NULL;
		cost = get_inst_from_bb(cur, ib, la, &inst);
		while (cur)
		{
			if (get_inst_from_bb(cur, ib, la, &tmp) < cost)
			{
				(instru_clear(&inst), instru_clear(&tmp));
				cost = get_inst_from_bb(cur, ib, la, &inst);
			}
			instru_clear(&tmp);
			cur = cur->next;
		}
/*    		(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb), instru_display(&inst));
		ft_printf("==> INSTRUCTIONS :\n");   */
		(instru_display(&inst), instru_exec(&inst, la, lb));
		(instru_clear(&inst), instru_clear(&tmp), stack_update_infos(lb, ib));
	}
	return (0);
}

/* int	get_final_stack(t_stack **la, t_infos *ia)
{
	t_inst	*instru;

	while (*lb)
	{
		instru = NULL;
		get_inst_from_b(*lb, ia, la, &instru);
 		(ft_printf("==>LISTE A :\n"), stack_display(la));
		(ft_printf("==>LISTE B :\n"), stack_display(lb));
		ft_printf("==> INSTRUCTIONS :\n");  
		instru_display(&instru);
		instru_exec(&instru, la, lb);
		instru_clear(&instru);
		stack_update_infos(la, ia);
	}
	move_to_top(ia->min, *ia, &instru, A);
	instru_exec(&instru, la, lb);
	instru_display(&instru);
	instru_clear(&instru);
	stack_update_infos(la, ia);
}
 */