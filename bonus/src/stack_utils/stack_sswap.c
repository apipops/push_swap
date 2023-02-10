/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:51:00 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 18:17:23 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	stack_sswap(t_stack **lsta, t_stack **lstb)
{
	stack_swap(lsta);
	stack_swap(lstb);
}
