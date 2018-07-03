/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionals_funcks_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:14:24 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 16:02:10 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swaplist(t_ls **array, int swap_this, int with_that)
{
	t_ls *tmp;

	tmp = array[swap_this];
	array[swap_this] = array[with_that];
	array[with_that] = tmp;
	tmp = NULL;
}

t_ls	**r_sort_list(t_ls **direct)
{
	int start;
	int end;

	start = 0;
	if (direct == NULL)
		return (direct);
	end = ft_count_list(direct) - 1;
	while (start <= end)
	{
		ft_swaplist(direct, start, end);
		start++;
		end--;
	}
	return (direct);
}

int		ft_double_array_count(char **array)
{
	int count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

void	ft_try_output_with_r(char *std)
{
	int	i;

	i = ft_strlen(std);
	if (std[i - 1] == '/')
		i--;
	write(1, std, i);
	write(1, ":", 1);
	write(1, "\n", 1);
}

t_ls	*addlst(t_ls *new)
{
	new = (t_ls*)malloc(sizeof(t_ls));
	if (new == NULL)
		return (NULL);
	new->name = (char*)malloc(sizeof(char) * 2);
	new->name_tmp = NULL;
	new->name[1] = '\0';
	new->leng = 0;
	new->time = 0;
	return (new);
}
