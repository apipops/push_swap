/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:25:37 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 18:16:50 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	stack_display(t_stack **lst)
{
	t_stack	*cur;

	if (lst == 0 || *lst == 0)
	{
		ft_printf("[empty stack]\n");
		return ;
	}
	cur = *lst;
	while (cur)
	{
		ft_printf("nb : %d\n", cur->nb);
		cur = cur->next;
	}
}
