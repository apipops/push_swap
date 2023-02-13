/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:31:16 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:06:31 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

void	stack_swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_get_size(lst) < 2)
		return ;
	else
	{
		first = *lst;
		second = (*lst)->next;
		first->next = second->next;
		first->pos = 2;
		second->next = first;
		second->pos = 1;
		*lst = second;
	}
}
