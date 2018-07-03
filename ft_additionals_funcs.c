/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionals_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:05:23 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/19 16:58:52 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_try_output(char *std)
{
	int	i;

	i = ft_strlen(std);
	write(1, std, i);
	write(1, ":", 1);
	write(1, "\n", 1);
}

int		ft_count_list(t_ls **count)
{
	int	i;

	i = 0;
	while (count[i])
		i++;
	return (i);
}

int		ft_count_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		ft_max_len(int *str)
{
	int	i;
	int	z;
	int	k;

	i = 0;
	z = 1;
	while (str[i])
	{
		if (str[i] < str[z])
			i++;
		else
		{
			z = i;
			i++;
		}
	}
	k = str[z];
	free(str);
	return (k);
}
