/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:26:14 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 15:16:03 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

void	put_elem_in_order(t_stack **lst, t_stack *new)
{
	t_stack	*cur;

	if (lst == 0 || *lst == 0 || new->nb < (*lst)->nb)
	{
		stack_add_front(lst, new);
		return ;
	}
	cur = *lst;
	while (cur->next)
	{
		if (cur->nb < new->nb && cur->next->nb > new->nb)
		{
			new->next = cur->next;
			cur->next = new;
			return ;
		}
		cur = cur->next;
	}
	if (new->nb > cur->nb)
		cur->next = new;
	else
		stack_add_front(lst, new);
}

t_stack	**create_ordered_stack(t_stack **ordered, t_stack **lst)
{
	t_stack	*cur;
	t_stack	*new;

	cur = *lst;
	while (cur)
	{
		new = stack_create_new(cur->nb);
		if (!new)
			return (stack_clear(ordered), NULL);
		put_elem_in_order(ordered, new);
		cur = cur->next;
	}
	return (ordered);
}

t_stack	*get_first_bel_med(t_stack **lst, int median)
{
	t_stack	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->nb <= median)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_stack	*get_first_abo_med(t_stack **lst, int median)
{
	t_stack	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->nb > median)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_median	get_median(t_stack **lst, t_infos *infos)
{
	t_stack		*ordered;
	t_stack		*cur;
	t_median	median;
	int			i;

	ordered = NULL;
	create_ordered_stack(&ordered, lst);
	if (!ordered)
		return ((t_median){0, 0});
	cur = ordered;
	i = 1;
	median.count = infos->size / 2 + infos->size % 2;
	while (i < median.count)
	{
		cur = cur->next;
		i++;
	}
	median.val = cur->nb;
	stack_clear(&ordered);
	return (median);
}
