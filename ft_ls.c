/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:43:05 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 15:38:15 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	**ft_files_link_join(t_ls **files, t_ls **link)
{
	int		i;
	int		z;
	t_ls	**output;

	i = ft_count_list(link);
	z = ft_count_list(files);
	output = (t_ls**)malloc(sizeof(t_ls*) * (z + i + 1));
	output = ft_files_link_join_helper(files, link, output);
	return (sortlist(output, 0, i - 1));
}

int		ft_readlength(char *std, int a)
{
	struct dirent	*entry;
	int				i;
	DIR				*dir;

	i = 0;
	dir = opendir(std);
	if (!dir)
		return (0);
	while ((entry = readdir(dir)) != NULL)
	{
		if ((entry->d_name[0] == '.' || !ft_strcmp(entry->d_name, "..")) && !a)
			continue;
		i++;
	}
	closedir(dir);
	return (i);
}

t_ls	**ft_readadd(int length, char *std, int a)
{
	t_ls	**n;
	DIR		*dir;

	dir = opendir(std);
	if (!dir)
		return (0);
	n = (t_ls**)malloc(sizeof(t_ls*) * (length + 1));
	n[length] = 0;
	n = ft_readadd_helper(n, dir, std, a);
	closedir(dir);
	return (n);
}

t_ls	**sortlist(t_ls **new, int start, int end)
{
	t_ls	*pivot;
	int		s;
	int		e;

	s = start;
	e = end;
	if (end <= start)
		return (new);
	pivot = new[(s + e) / 2];
	while (s <= e)
	{
		while (ft_strcmp(new[s]->name, pivot->name) < 0)
			s++;
		while (ft_strcmp(new[e]->name, pivot->name) > 0)
			e--;
		if (s <= e)
		{
			ft_swaplist(new, s, e);
			s++;
			e--;
		}
	}
	sortlist(new, start, e);
	sortlist(new, s, end);
	return (new);
}
