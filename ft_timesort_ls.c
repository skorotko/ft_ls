/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timesort_ls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:19:15 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/12 15:19:16 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	**ft_time_sortlist(t_ls **new, int start, int end)
{
	long long	pivot;
	int			s;
	int			e;

	s = start;
	e = end;
	if (end <= start)
		return (new);
	pivot = new[(s + e) / 2]->time;
	while (s <= e)
	{
		while (new[s]->time > pivot)
			s++;
		while (new[e]->time < pivot)
			e--;
		if (s <= e)
		{
			ft_swaplist(new, s, e);
			s++;
			e--;
		}
	}
	ft_time_sortlist(new, start, e);
	ft_time_sortlist(new, s, end);
	return (new);
}

t_ls	**ft_time_sortlist_ascii(t_ls **new)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 1;
	if (new)
		while (new[count] && new[count2])
		{
			if (new[count]->time == new[count2]->time)
			{
				while (new[count]->time == new[count2]->time && new[count2 + 1])
					count2++;
				if (new[count]->time == new[count2]->time && new[count2])
					count2++;
				new = sortlist(new, count, count2 - 1);
				count = count2;
				count2++;
			}
			else
			{
				count++;
				count2++;
			}
		}
	return (new);
}

t_ls	**ft_time_sort_st(t_ls **new, int start, int end)
{
	t_ls **sort;

	sort = ft_time_sortlist(new, start, end);
	sort = ft_time_sortlist_ascii(sort);
	return (sort);
}
