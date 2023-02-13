/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:05:36 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:39:09 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

t_stack	*stack_create_new(int nb)
{
	t_stack	*elem;

	elem = malloc(sizeof (t_stack));
	if (!elem)
		return (0);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}
