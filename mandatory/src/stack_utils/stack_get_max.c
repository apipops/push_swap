/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:56:05 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:06:02 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

t_stack	*stack_get_max(t_stack **lst)
{
	int			i;
	t_stack		*max;
	t_stack		*cur;

	if (lst == 0 || *lst == 0)
		return (NULL);
	i = 1;
	max = (*lst);
	cur = (*lst);
	while (cur)
	{
		if (cur->nb > max->nb)
			max = cur;
		cur = cur->next;
		i++;
	}
	return (max);
}
