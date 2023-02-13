/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_elem_sup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:10:56 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 12:39:09 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

t_stack	*stack_get_elem_sup(t_stack **lst, t_infos infos, int nb)
{
	t_stack	*superior;
	t_stack	*cur;

	if (lst == 0 || *lst == 0)
		return (NULL);
	if (nb > infos.max->nb)
		return (infos.min);
	superior = *lst;
	while (superior && superior->nb < nb)
		superior = superior->next;
	if (!superior)
		return (NULL);
	cur = *lst;
	while (cur)
	{
		if (cur->nb > nb && cur->nb < superior->nb)
			superior = cur;
		cur = cur->next;
	}
	return (superior);
}
