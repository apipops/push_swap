/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_delete_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:24:46 by avast             #+#    #+#             */
/*   Updated: 2023/02/07 14:55:07 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

void	instru_delete_one(t_inst **instru, int pos)
{
	t_inst	*tmp;
	t_inst	*cur;
	int			i;

	if (!instru || !*instru)
		return ;
	if (pos == 1)
	{
		tmp = *instru;
		*instru = (*instru)->next;
		free(tmp);
		return ;
	}
	i = 1;
	cur = *instru;
	while (i < pos - 1)
	{
		cur = cur->next;
		i++;
	}
	tmp = cur->next;
	cur->next = cur->next->next;
	free(tmp);
	return ;
}
