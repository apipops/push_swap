/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:16:40 by avast             #+#    #+#             */
/*   Updated: 2023/02/09 12:18:40 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

/* STACK UTILS */
void		stack_add_back(t_stack **lst, t_stack *new);
void		stack_add_front(t_stack **lst, t_stack *new);
int			stack_check_exist(t_stack **lst, int nb);
int			stack_check_order(t_stack **lst);
void		stack_clear(t_stack **lst);
t_stack		*stack_create_new(int nb);
void		stack_display(t_stack **lst);
t_stack		*stack_dup_elem(t_stack *elem);
t_infos		stack_get_infos(t_stack **lst);
t_stack		*stack_get_max(t_stack **lst);
t_stack		*stack_get_min(t_stack **lst);
int			stack_get_position_inf(t_stack **lst, t_infos infos, int nb);
t_stack		*stack_get_elem_inf(t_stack **lst, t_infos infos, int nb);
t_stack		*stack_get_elem_sup(t_stack **lst, t_infos infos, int nb);
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
t_infos		stack_update_infos(t_stack **lst, t_infos *infos);

/* INSTRUCTION UTILS */
void		instru_add_back(t_inst **instru, t_inst *new);
void		instru_clear(t_inst **instru);
t_inst		*instru_create_new(int type, char stack);
void		instru_delete_one(t_inst **instru, int pos);
void		instru_display_one(t_inst *instru);
void		instru_display(t_inst **instru);
void		instru_exec_one(t_inst *instru, t_stack **lst1, t_stack **lst2);
void		instru_exec(t_inst **instru, t_stack **la, t_stack **lb);
int			instru_get_size(t_inst **instru);

/* PARSING */
int			number_length(char *str);
int			is_numeric_val(char *str);
int			has_duplicate(t_stack **lst, int nb);
long int	ft_atol(const char *nptr);
t_stack		**create_stack(t_stack **lsta, int ac, char **av);

/* SORTING */
void		sort_two(t_stack **lst, t_infos *infos);
void		sort_three(t_stack **lst, t_infos *infos);
int			sort_five(t_stack **lsta, t_infos *infosa, t_stack	**lstb);
//void		sort_maxi(t_stack **la, t_infos *ia, t_stack **lb);
void		sort_maxi_1(t_stack **la, t_infos *ia, t_stack **lb, t_median med);
void		sort_maxi_2(t_stack **la, t_infos *ia, t_stack **lb);
void		sort_maxi_3(t_stack **la, t_infos *ia, t_stack **lb);

t_stack		**get_already_sort(t_stack **la, t_infos *ia, t_stack **sort);
int			sort_max_1b(t_stack **la, t_infos *ib, t_stack **lb);
int			sort_max_2b(t_stack **la, t_infos *ib, t_stack **lb);
int			push_to_lb(t_stack **la, t_infos *ia, t_stack **lb, t_infos *ib);
int			push_back_to_la(t_stack **la, t_infos *ib, t_stack **lb);
int			sort_maxi(t_stack **la, t_infos *ia, t_stack **lb, t_infos *ib);

/* MEDIAN */
t_stack		**create_ordered_stack(t_stack **ordered, t_stack **lst);
t_stack		*get_first_bel_med(t_stack **lst, int median);
t_median	get_median(t_stack **lst, t_infos *infos);
void		put_elem_in_order(t_stack **lst, t_stack *new);

/* INSTRUCTIONS */
t_inst		**add_x_instru(t_inst **instru, int i, int type, char stack);
t_inst		**get_instru_a(t_stack *elem, t_infos *infosa, t_inst **instru);
t_inst		**get_instru_b(t_stack *elem, t_stack **lstb, t_inst **instru);
int			get_instrus(t_stack *ele, t_infos *ia, t_stack **lb, t_inst **ins);
int			get_inst_from_a(t_stack *el, t_infos *ia, t_stack **lb, t_inst **i);
int			get_inst_from_b(t_stack *el, t_infos *ia, t_stack **la, t_inst **i);
t_inst		**merge_duplicate_instru(t_inst **instru);
t_inst		**move_to_top(t_stack *el, t_infos inf, t_inst **inst, char stack);

int			get_inst_from_bb(t_stack *e, t_infos *ib, t_stack **la, t_inst **i);

#endif