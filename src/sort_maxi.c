/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_maxi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:01:57 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 19:24:41 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

void	sort_maxi(t_stack **la, t_infos *ia, t_stack **lb)
{
/*  	t_median	median;

	median = get_median(la, ia); 

	sort_maxi_1(la, ia, lb, median); */
	t_infos	ib;

	stack_update_infos(lb, &ib);
	sort_max_1b(la, ia, lb);
	sort_max_2b(la, &ib, lb);
	//sort_maxi_2(la, ia, lb);
/* 	ft_printf("----BEFORE SORT THREE-------\n");
	(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb)); */
	//sort_three(la, ia);
/* 	ft_printf("----AFTER SORT THREE-------\n");
	(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb)); */
	//sort_maxi_3(la, ia, lb);
}

t_stack	**get_sort(t_stack **la, t_infos *ia, t_stack **sort)
{
	t_stack	*last;

	last = stack_dup_elem(ia->min);
	if (!last)
		return (NULL);
	stack_add_back(sort, last);
	while (stack_get_elem_sup(la, *ia, last->nb)
		&& stack_get_elem_sup(la, *ia, last->nb)->pos > last->pos)
	{
		last = stack_dup_elem(stack_get_elem_sup(la, *ia, last->nb));
		if (!last)
			return (NULL);
		stack_add_back(sort, last);
	}
	return (sort);
}

int	sort_max_1b(t_stack **la, t_infos *ia, t_stack **lb)
{
	t_stack	*sorted;
	int		stop;

	sorted = NULL;
	if (!get_sort(la, ia, &sorted))
		return (-1);
	if (stack_get_size(&sorted) > 3)
		stop = stack_get_size(&sorted);
	else
		stop = 3;
	while (ia->size > stop)
	{
		if (stack_check_exist(&sorted, (*la)->nb) == OK)
			(stack_rotate(la), ft_printf(RA));
		else
			(stack_push(la, lb), ft_printf(PB), stack_update_infos(la, ia));
	}
	stack_clear(&sorted);
	return (0);
}

int	sort_max_2b(t_stack **la, t_infos *ib, t_stack **lb)
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
 		(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb), instru_display(&inst));
		ft_printf("==> INSTRUCTIONS :\n"); 
		(instru_display(&inst), instru_exec(&inst, la, lb));
		(instru_clear(&inst), instru_clear(&tmp), stack_update_infos(lb, ib));
	}
	return (0);
}

void	sort_maxi_1(t_stack **la, t_infos *ia, t_stack **lb, t_median med)
{
	t_stack		*cur;
	t_inst		*inst;
	t_inst		*tmp;
	int			cost;

	while (med.count)
	{
		cur = *la;
		inst = NULL;
		tmp = NULL;
		cost = get_inst_from_a(get_first_bel_med(la, med.val), ia, lb, &inst);
		while (cur)
		{
			if (cur->nb <= med.val && get_inst_from_a(cur, ia, lb, &tmp) < cost)
			{
				(instru_clear(&inst), instru_clear(&tmp));
				cost = get_inst_from_a(cur, ia, lb, &inst);
			}
			instru_clear(&tmp);
			cur = cur->next;
		}
/* 		(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb));
		//instru_display(&inst);
		ft_printf("==> INSTRUCTIONS :\n"); */
		(instru_display(&inst), instru_exec(&inst, la, lb));
		(instru_clear(&inst), instru_clear(&tmp), stack_update_infos(la, ia));
		med.count--;
	}
}

void	sort_maxi_2(t_stack **la, t_infos *ia, t_stack **lb)
{
	t_stack		*cur;
	t_inst		*inst;
	t_inst		*tmp;
	int			cost;

	while (ia->size > 3)
	{
		cur = *la;
		inst = NULL;
		tmp = NULL;
		cost = get_inst_from_a(cur, ia, lb, &inst);
		while (cur)
		{
			if (get_inst_from_a(cur, ia, lb, &tmp) < cost)
			{
				(instru_clear(&inst), instru_clear(&tmp));
				cost = get_inst_from_a(cur, ia, lb, &inst);
			}
			instru_clear(&tmp);
			cur = cur->next;
		}
/* 		(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb), instru_display(&inst));
		ft_printf("==> INSTRUCTIONS :\n"); */
		(instru_display(&inst), instru_exec(&inst, la, lb));
		(instru_clear(&inst), instru_clear(&tmp), stack_update_infos(la, ia));
	}
}

 void	sort_maxi_3(t_stack **la, t_infos *ia, t_stack **lb)
{
	t_inst	*instru;

	while (*lb)
	{
		instru = NULL;
		get_inst_from_b(*lb, ia, la, &instru);
/*   		(ft_printf("==>LISTE A :\n"), stack_display(la));
		(ft_printf("==>LISTE B :\n"), stack_display(lb));
		ft_printf("==> INSTRUCTIONS :\n");  */
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

/* void	sort_maxi_3(t_stack **la, t_infos *ib, t_stack **lb)
{
	t_stack		*cur;
	t_inst		*inst;
	t_inst		*tmp;
	int			cost;

	cur = *lb;
	while (cur)
	{
		inst = NULL;
		tmp = NULL;
		cost = get_inst_from_b(cur, ib, lb, &inst);
		while (cur)
		{
			if (get_inst_from_b(cur, ib, lb, &tmp) < cost)
			{
				(instru_clear(&inst), instru_clear(&tmp));
				cost = get_inst_from_a(cur, ib, lb, &inst);
			}
			instru_clear(&tmp);
			cur = cur->next;
		}
		(ft_printf("==> LISTE A :\n"), stack_display(la), ft_printf("==> LISTE b :\n"), stack_display(lb), instru_display(&inst));
		ft_printf("==> INSTRUCTIONS :\n"); 
		(instru_display(&inst), instru_exec(&inst, la, lb));
		(instru_clear(&inst), instru_clear(&tmp), stack_update_infos(la, ib));
	}
}
 */