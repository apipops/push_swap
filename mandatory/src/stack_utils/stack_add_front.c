/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:05:09 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:05:11 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

void	stack_add_front(t_stack **lst, t_stack *new)
{
	if (new == 0)
		return ;
	new->next = *lst;
	*lst = new;
	stack_update_positions(lst);
}
