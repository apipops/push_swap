/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update_positions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:10:13 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:39:09 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	stack_update_positions(t_stack **lst)
{
	int		i;
	t_stack	*cur;

	if (lst == 0 || *lst == 0)
		return ;
	i = 1;
	cur = *lst;
	while (cur)
	{
		cur->pos = i;
		cur = cur->next;
		i++;
	}
}
