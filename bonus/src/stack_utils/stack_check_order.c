/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:05:17 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 18:16:37 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

int	stack_check_order(t_stack **lst)
{
	t_stack	*cur;

	if (lst == 0 || *lst == 0 || stack_get_size(lst) == 1)
		return (OK);
	cur = *lst;
	while (cur->next)
	{
		if (cur->nb > cur->next->nb)
			return (KO);
		cur = cur->next;
	}
	return (OK);
}
