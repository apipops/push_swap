/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:53 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 18:17:19 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../../libft/libft.h"

void	stack_rrotate(t_stack	**lsta, t_stack **lstb)
{
	stack_rotate(lsta);
	stack_rotate(lstb);
}
