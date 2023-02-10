/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:04:49 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 18:16:30 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*cur;

	if (*lst == 0)
	{
		new->pos = 1;
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->pos = stack_get_size(lst);
}
