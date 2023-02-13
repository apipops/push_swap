/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:46:34 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:06:17 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

void	stack_reverse_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*cur;

	if (lst == 0 || *lst == 0 || stack_get_size(lst) == 1)
		return ;
	cur = *lst;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	last = cur->next;
	cur->next = NULL;
	last->next = *lst;
	*lst = last;
	stack_update_positions(lst);
}
