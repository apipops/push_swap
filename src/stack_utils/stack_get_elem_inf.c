/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_elem_inf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:10:56 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:05:54 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

t_stack	*stack_get_elem_inf(t_stack **lst, t_infos infos, int nb)
{
	t_stack	*inferior;
	t_stack	*cur;

	if (lst == 0 || *lst == 0)
		return (NULL);
	if (nb < infos.min->nb)
		return (infos.max);
	inferior = *lst;
	while (inferior && inferior->nb > nb)
		inferior = inferior->next;
	cur = *lst;
	while (cur)
	{
		if (cur->nb < nb && cur->nb > inferior->nb)
			inferior = cur;
		cur = cur->next;
	}
	return (inferior);
}
