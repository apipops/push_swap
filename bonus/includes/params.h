/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:12:26 by avast             #+#    #+#             */
/*   Updated: 2023/02/13 10:28:12 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>

# define OK 1
# define KO 0
# define ERROR "Error\n"

# define A 'a'
# define B 'b'

# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define SARA "sa\nra\n"
# define SARRA "sa\nrra\n"

typedef struct s_stack
{
	int				nb;
	int				pos;
	struct s_stack	*next;
}	t_stack;

#endif