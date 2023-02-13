/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:35:55 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:49:54 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../../libft/libft.h"

int	read_instru(t_stack **lsta, t_stack **lstb)
{
	char	*instru;

	instru = get_next_line(0);
	while (instru)
	{
		if (apply_instru(instru, lsta, lstb) == -1)
			return (free(instru), -1);
		free(instru);
		instru = get_next_line(0);
	}
	return (0);
}

int	apply_instru(char *instru, t_stack **la, t_stack **lb)
{
	if (!ft_strcmp(instru, PA))
		return (stack_push(lb, la), 0);
	if (!ft_strcmp(instru, PB))
		return (stack_push(la, lb), 0);
	if (!ft_strcmp(instru, RA))
		return (stack_rotate(la), 0);
	if (!ft_strcmp(instru, RB))
		return (stack_rotate(lb), 0);
	if (!ft_strcmp(instru, RR))
		return (stack_rrotate(la, lb), 0);
	if (!ft_strcmp(instru, RRA))
		return (stack_reverse_rotate(la), 0);
	if (!ft_strcmp(instru, RRB))
		return (stack_reverse_rotate(lb), 0);
	if (!ft_strcmp(instru, RRR))
		return (stack_rreverse_rotate(la, lb), 0);
	if (!ft_strcmp(instru, SA))
		return (stack_swap(la), 0);
	if (!ft_strcmp(instru, SB))
		return (stack_swap(lb), 0);
	if (!ft_strcmp(instru, SS))
		return (stack_sswap(la, lb), 0);
	return (-1);
}
