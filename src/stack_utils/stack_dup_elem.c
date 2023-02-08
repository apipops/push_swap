/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dup_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:02:44 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 18:05:05 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

t_stack	*stack_dup_elem(t_stack *elem)
{
	t_stack	*dup;

	dup = malloc(sizeof (t_stack));
	if (!dup)
		return (0);
	dup->nb = elem->nb;
	dup->pos = elem->pos;
	dup->next = NULL;
	return (dup);
}
