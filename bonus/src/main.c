/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:44:08 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 10:26:03 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../../libft/libft.h"

int	main(int ac, char **av)
{
	t_stack	*lsta;
	t_stack	*lstb;

	if (ac < 2)
		return (0);
	lsta = NULL;
	lstb = NULL;
	create_stack(&lsta, ac, av);
	if (!lsta)
		return (ft_putstr_fd(ERROR, 2), 0);
	if (read_instru(&lsta, &lstb) == -1)
		return (ft_putstr_fd(ERROR, 2), 0);
	if (stack_check_order(&lsta) == OK && stack_get_size(&lstb) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(&lsta);
	stack_clear(&lstb);
	return (0);
}
