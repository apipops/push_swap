/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:51:00 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:39:09 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	stack_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (from == 0 || *from == 0)
		return ;
	tmp = (*from)->next;
	stack_add_front(to, *from);
	*from = tmp;
	stack_update_positions(from);
}
