/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_exist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:10:23 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 19:03:40 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

int	stack_check_exist(t_stack **lst, int nb)
{
	int		i;
	t_stack	*cur;

	if (lst == 0 || *lst == 0)
		return (KO);
	i = 1;
	cur = *lst;
	while (cur)
	{
		if (cur->nb == nb)
			return (OK);
		i++;
		cur = cur->next;
	}
	return (KO);
}
