/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:19:14 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:39:09 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	instru_add_back(t_inst **instru, t_inst *new)
{
	t_inst	*cur;

	if (*instru == 0)
	{
		*instru = new;
		return ;
	}
	cur = *instru;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
