/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:15:35 by avast             #+#    #+#             */
/*   Updated: 2023/02/08 11:11:55 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/params.h"
#include "../includes/protos.h"
#include "../libft/libft.h"

int	number_length(char *str)
{
	if (str == 0 || *str == 0)
		return (0);
	while (*str == '0')
		str++;
	return (ft_strlen(str));
}

int	is_numeric_val(char *str)
{
	int	nb_flag;
	int	sign_flag;

	sign_flag = 0;
	nb_flag = 0;
	if (number_length(str) > 11)
		return (0);
	while (*str)
	{
		if (sign_flag < 2 && ((*str >= '0' && *str <= '9')
				|| *str == '+' || *str == '-'))
		{
			if (*str >= '0' && *str <= '9')
				nb_flag++;
			if ((*str == '+' || *str == '-') && nb_flag == 1)
				return (0);
			else if ((*str == '+' || *str == '-') && nb_flag == 0)
				sign_flag++;
			str++;
		}
		else
			return (0);
	}
	return (1);
}

int	has_duplicate(t_stack **lst, int nb)
{
	t_stack	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->nb == nb)
			return (1);
		cur = cur->next;
	}
	return (0);
}

long int	ft_atol(const char *nptr)
{
	long int	i;
	long int	sign;
	long int	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}	
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - 48;
		i++;
	}
	return (n * sign);
}

t_stack	**create_stack(t_stack **lsta, int ac, char **av)
{
	int			i;
	long int	nb;
	t_stack		*elem;

	i = 1;
	while (i < ac)
	{
		if (!is_numeric_val(av[i]))
			return (stack_clear(lsta), NULL);
		else
		{
			nb = ft_atol(av[i]);
			if (nb < INT_MIN || nb > INT_MAX || has_duplicate(lsta, nb))
				return (stack_clear(lsta), NULL);
			elem = stack_create_new((int)nb);
			if (!elem)
				return (stack_clear(lsta), NULL);
			stack_add_back(lsta, elem);
		}		
		i++;
	}
	return (lsta);
}

/* int	main(int ac, char **av)
{
	t_stack	*lst;

	lst = NULL;
	stack_display(read_params(&lst, ac, av));
	stack_clear(&lst);
	return (0);
}
 */