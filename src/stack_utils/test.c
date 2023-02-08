/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:34:29 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 10:52:43 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/params.h"
#include "../../includes/protos.h"
#include "../../libft/libft.h"

int	main(void)
{
	t_stack	*lista;
	t_stack	*listb;
	t_stack *nul;
	t_stack *size1;
	t_stack *size2;

	lista = stack_create_new(2);
	lista->next = stack_create_new(3);
	lista->next->next = stack_create_new(4);
	lista->next->next->next = stack_create_new(5);
	lista->next->next->next->next = stack_create_new(6);
	listb = stack_create_new(20);
	listb->next = stack_create_new(30);
	listb->next->next = stack_create_new(40);
	listb->next->next->next = stack_create_new(50);
	listb->next->next->next->next = stack_create_new(60);
	nul = 0;
	size1 = stack_create_new(100);
	size2 = stack_create_new(200);
	size2->next = stack_create_new(201);

	ft_printf("-------------STACKS---------------\n");
	ft_printf("--> list a\n");
	stack_display(&lista);
	ft_printf("--> list b\n");
	stack_display(&listb);
	ft_printf("--> nul\n");
	stack_display(&nul);
	ft_printf("--> size 1\n");
	stack_display(&size1);
	ft_printf("--> size2\n");
	stack_display(&size2);

	ft_printf("\n\n--------------add front---------------\n");
	stack_add_front(&lista, stack_create_new(1));
	stack_add_front(&listb, stack_create_new(10));
	ft_printf("-> list a\n");
	stack_display(&lista);
	ft_printf("-> list b\n");
	stack_display(&listb);

	ft_printf("\n\n--------------get size---------------\n");
	ft_printf("taille lista : %d\n", stack_get_size(&lista));
	ft_printf("taille nul : %d\n", stack_get_size(&nul));
	ft_printf("taille size1 : %d\n", stack_get_size(&size1));

	ft_printf("\n\n--------------sswap---------------\n");
	stack_sswap(&lista, &listb);
	ft_printf("-> list a\n");
	stack_display(&lista);
	ft_printf("-> list b\n");
	stack_display(&listb);
	stack_swap(&nul);
	ft_printf("-> list nul\n");
	stack_display(&nul);
	stack_swap(&size1);
	ft_printf("-> list size1\n");
	stack_display(&size1);
	stack_swap(&size2);
	ft_printf("-> list size2\n");
	stack_display(&size2);


	ft_printf("\n\n--------------rrotate---------------\n");
	stack_rrotate(&lista, &listb);
	ft_printf("-> list a\n");
	stack_display(&lista);
	ft_printf("-> list b\n");
	stack_display(&listb);
	stack_rotate(&nul);
	ft_printf("-> list nul\n");
	stack_display(&nul);
	stack_rotate(&size1);
	ft_printf("-> list size1\n");
	stack_display(&size1);
	stack_rotate(&size2);
	ft_printf("-> list size2\n");
	stack_display(&size2);


	ft_printf("\n\n--------------reverse rrotate---------------\n");
	stack_rreverse_rotate(&lista, &listb);
	ft_printf("-> list a\n");
	stack_display(&lista);
	ft_printf("-> list b\n");
	stack_display(&listb);
	stack_reverse_rotate(&nul);
	ft_printf("-> list nul\n");
	stack_display(&nul);
	stack_reverse_rotate(&size1);
	ft_printf("-> list size1\n");
	stack_display(&size1);
	stack_reverse_rotate(&size2);
	ft_printf("-> list size2\n");
	stack_display(&size2);

	ft_printf("\n\n--------------push a---------------\n");
	stack_push(&listb, &lista);
	ft_printf("-> list a\n");
	stack_display(&lista);
	ft_printf("-> list b\n");
	stack_display(&listb);
	ft_printf("-----from nul to size2----------\n");
	stack_push(&nul, &size2);
	ft_printf("-> list nul\n");
	stack_display(&nul);
	ft_printf("-> list size2\n");
	stack_display(&size2);
	ft_printf("-----from size1 to nul----------\n");
	stack_push(&size1, &nul);
	ft_printf("-> list size1\n");
	stack_display(&size1);
	ft_printf("-> list nul\n");
	stack_display(&nul);
	ft_printf("-----RESET nulet size1\n");
	stack_push(&nul, &size1);

	ft_printf("\n\n--------------get max---------------\n");
	ft_printf("max lista : %d\n", stack_get_max(&lista));
	ft_printf("max nul : %d\n", stack_get_max(&nul));
	ft_printf("max size1 : %d\n", stack_get_max(&size1));

	ft_printf("\n\n--------------get min---------------\n");
	ft_printf("min lista : %d\n", stack_get_min(&lista));
	ft_printf("min listb : %d\n", stack_get_min(&listb));
	ft_printf("min nul : %d\n", stack_get_min(&nul));
	ft_printf("min size1 : %d\n", stack_get_min(&size1));

	ft_printf("\n\n--------------check order---------------\n");
	ft_printf("order lista : %d\n", stack_check_order(&lista));
	ft_printf("order listb : %d\n", stack_check_order(&listb));
	ft_printf("order nul : %d\n", stack_check_order(&nul));
	ft_printf("order size1 : %d\n", stack_check_order(&size1));
	ft_printf("order size2 : %d\n", stack_check_order(&size2));


	stack_clear(&lista);
	stack_clear(&listb);
	stack_clear(&nul);
	stack_clear(&size1);
	stack_clear(&size2);
	return (0);
}
