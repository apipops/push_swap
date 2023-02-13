/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:05:08 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:39:09 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	instru_display_one(t_inst *instru)
{
	if (instru->type == ROTATE)
		ft_printf("r");
	else if (instru->type == REV_ROT)
		ft_printf("rr");
	else if (instru->type == RROTATE)
		ft_printf("rr\n");
	else if (instru->type == RREV_ROT)
		ft_printf("rrr\n");
	else if (instru->type == SWAP)
		ft_printf("s");
	else if (instru->type == SSWAP)
		ft_printf("ss\n");
	else if (instru->type == PUSH)
		ft_printf("p");
}

void	instru_display(t_inst **instru)
{
	t_inst	*cur;

	cur = *instru;
	while (cur)
	{
		if (cur->stack == A)
		{
			instru_display_one(cur);
			if (cur->type != RROTATE && cur->type != RREV_ROT
				&& cur->type != SSWAP && cur->type != 0)
				ft_printf("a\n");
		}
		if (cur->stack == B)
		{
			instru_display_one(cur);
			if (cur->type != RROTATE && cur->type != RREV_ROT
				&& cur->type != SSWAP && cur->type != 0)
				ft_printf("b\n");
		}
		cur = cur->next;
	}
}
