/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_create_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:19:14 by avast             #+#    #+#             */
/*   Updated: 2023/02/07 14:55:07 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

t_inst	*instru_create_new(int type, char stack)
{
	t_inst	*elem;

	elem = malloc(sizeof (t_inst));
	if (!elem)
		return (0);
	elem->type = type;
	elem->stack = stack;
	elem->next = NULL;
	return (elem);
}
