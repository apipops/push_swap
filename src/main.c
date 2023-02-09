/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:44:08 by avast             #+#    #+#             */
/*   Updated: 2023/02/09 13:25:26 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

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
	//ft_printf("%p\n", &lsta);
	if (!lsta)
		return (ft_putstr_fd(ERROR, 2), 0);
	infosa = stack_get_infos(&lsta);
	infosb = stack_get_infos(&lstb);
  	if (infosa.size == 1)
		return (stack_display(&lsta), stack_clear(&lsta), 0);
	else if (infosa.size == 2)
		sort_two(&lsta, &infosa);
	else if (infosa.size <= 3)
		sort_three(&lsta, &infosa);
	else if (infosa.size <= 5)
		sort_five(&lsta, &infosa, &lstb);
	else
		sort_maxi(&lsta, &infosa, &lstb, &infosb);
/*     ft_printf("==> LISTE A :\n");
	stack_display(&lsta);
	ft_printf("==> LISTE B :\n");
	stack_display(&lstb);   */
	stack_clear(&lsta);
	stack_clear(&lstb);
	return (0);
}
