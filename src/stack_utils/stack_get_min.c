/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:56:05 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:06:04 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

t_stack	*stack_get_min(t_stack **lst)
{
	int			i;
	t_stack		*min;
	t_stack		*cur;

	if (lst == 0 || *lst == 0)
		return (NULL);
	i = 1;
	min = (*lst);
	cur = (*lst);
	while (cur)
	{
		if (cur->nb < min->nb)
			min = cur;
		cur = cur->next;
		i++;
	}
	return (min);
}
