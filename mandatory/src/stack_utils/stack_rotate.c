/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:53 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:39:09 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	stack_rotate(t_stack	**lst)
{
	t_stack	*first;
	t_stack	*cur;

	if (lst == 0 || *lst == 0 || stack_get_size(lst) == 1)
		return ;
	first = *lst;
	*lst = first->next;
	cur = *lst;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = first;
	first->next = NULL;
	stack_update_positions(lst);
}
