/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_execute.c                                   :+:      :+:    :+:   */
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

void	instru_exec_one(t_inst *instru, t_stack **main_lst, t_stack **scd_lst)
{
	if (instru->type == ROTATE)
		stack_rotate(main_lst);
	else if (instru->type == REV_ROT)
		stack_reverse_rotate(main_lst);
	else if (instru->type == RROTATE)
		stack_rrotate(main_lst, scd_lst);
	else if (instru->type == RREV_ROT)
		stack_rreverse_rotate(main_lst, scd_lst);
	else if (instru->type == SWAP)
		stack_swap(main_lst);
	else if (instru->type == SSWAP)
		stack_sswap(main_lst, scd_lst);
	else if (instru->type == PUSH)
		stack_push(scd_lst, main_lst);
}

void	instru_exec(t_inst **instru, t_stack **la, t_stack **lb)
{
	t_inst	*cur;

	cur = *instru;
	while (cur)
	{
		if (cur->stack == A)
			instru_exec_one(cur, la, lb);
		if (cur->stack == B)
			instru_exec_one(cur, lb, la);
		cur = cur->next;
	}
}
