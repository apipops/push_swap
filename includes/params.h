/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:12:26 by avast             #+#    #+#             */
/*   Updated: 2023/02/10 15:59:07 by avast            ###   ########.fr       */
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

# define ROTATE 1
# define RROTATE 2
# define REV_ROT 3
# define RREV_ROT 4
# define SWAP 5
# define SSWAP 6
# define PUSH 7

# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define SARA "sa\nra\n"
# define SARRA "sa\nrra\n"

typedef struct s_stack
{
	int				nb;
	int				pos;
	struct s_stack	*next;
}	t_stack;

typedef struct s_limit
{
	int	val;
	int	position;
}	t_limit;

typedef struct s_median
{
	int	val;
	int	count;
}	t_median;

typedef struct s_infos
{
	int		size;
	t_stack	*max;
	t_stack	*min;
}	t_infos;

typedef struct s_instructs
{
	int					type;
	char				stack;
	struct s_instructs	*next;
}	t_inst;


#endif