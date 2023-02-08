/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:26:50 by avast             #+#    #+#             */
/*   Updated: 2023/02/07 14:55:07 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

int	instru_get_size(t_inst **instru)
{
	int			size;
	t_inst	*cur;

	size = 0;
	cur = *instru;
	while (cur)
	{
		if ((*instru)->type > 0)
			size++;
		cur = cur->next;
	}
	return (size);
}
