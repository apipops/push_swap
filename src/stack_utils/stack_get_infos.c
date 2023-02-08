/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:28:49 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:05:59 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

t_infos	stack_get_infos(t_stack **lst)
{
	t_infos	infos;

	infos.size = stack_get_size(lst);
	infos.max = stack_get_max(lst);
	infos.min = stack_get_min(lst);
	return (infos);
}
