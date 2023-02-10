/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:44:08 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 17:06:59 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

int	sort_stack(t_stack **lsta, t_stack **lstb, t_infos *ia, t_infos *ib)
{
	if (ia->size == 1)
		return (0);
	else if (ia->size == 2)
		sort_two(lsta, ia);
	else if (ia->size <= 3)
		sort_three(lsta, ia);
	else if (ia->size <= 5)
	{
		if (sort_five(lsta, ia, lstb) == -1)
			return (-1);
	}
	else
	{
		if (sort_maxi(lsta, ia, lstb, ib) == -1)
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*lsta;
	t_stack	*lstb;
	t_infos	infosa;
	t_infos	infosb;

	if (ac < 2)
		return (0);
	lsta = NULL;
	lstb = NULL;
	create_stack(&lsta, ac, av);
	if (!lsta)
		return (ft_putstr_fd(ERROR, 2), 0);
	stack_update_infos(&lsta, &infosa);
	stack_update_infos(&lstb, &infosb);
	if (sort_stack(&lsta, &lstb, &infosa, &infosb) == -1)
		ft_putstr_fd(ERROR, 2);
	stack_clear(&lsta);
	stack_clear(&lstb);
	return (0);
}
