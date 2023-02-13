/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:16:40 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 10:58:02 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

/* STACK UTILS */
void		stack_add_back(t_stack **lst, t_stack *new);;
void		stack_add_front(t_stack **lst, t_stack *new);
int			stack_check_order(t_stack **lst);
void		stack_clear(t_stack **lst);
t_stack		*stack_create_new(int nb);
void		stack_display(t_stack **lst);
int			stack_get_size(t_stack **lst);
void		stack_order_put(t_stack **lst, t_stack *new);
void		stack_push(t_stack **from, t_stack **to);
void		stack_sswap(t_stack **lsta, t_stack **lstb);
void		stack_swap(t_stack **lst);
void		stack_reverse_rotate(t_stack **lst);
void		stack_rotate(t_stack	**lst);
void		stack_rrotate(t_stack	**lsta, t_stack **lstb);
void		stack_rreverse_rotate(t_stack **lsta, t_stack **lstb);
void		stack_update_positions(t_stack **lst);

/* PARSING */
int			number_length(char *str);
int			is_numeric_val(char *str);
int			has_duplicate(t_stack **lst, int nb);
long int	ft_atol(const char *nptr);
t_stack		**create_stack(t_stack **lsta, int ac, char **av);

/* SORTING */
int			read_instru(t_stack **lsta, t_stack **lstb);
int			apply_instru(char *instru, t_stack **la, t_stack **lb);

#endif