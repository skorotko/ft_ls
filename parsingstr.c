/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:34:42 by skorotko          #+#    #+#             */
/*   Updated: 2018/02/02 12:34:44 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_errors(char c)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &c, 1);
	write(2, "\n", 1);
	write(2, "usage: ls [-Ralrt1] [file ...]\n", 32);
	exit(1);
}

int		ft_check_flags_len(char **flags)
{
	int	i;
	int	j;
	int	d;

	i = 1;
	d = 0;
	while (flags[i] && flags[i][0] == '-' && ft_strcmp(flags[i], "--") &&
		flags[i][1] != '\0')
	{
		j = 0;
		while (flags[i][++j])
		{
			if (flags[i][j] == 'l' || flags[i][j] == 'a' ||
				flags[i][j] == '1' || flags[i][j] == 'R' ||
				flags[i][j] == 'r' || flags[i][j] == 't')
				d++;
			else
				ft_write_errors(flags[i][j]);
		}
		i++;
	}
	return (d);
}

t_ls	**ft_check_flags_lst(char **flags, int k)
{
	int		i;
	int		j;
	int		d;
	t_ls	**f;

	i = 1;
	d = 0;
	f = (t_ls**)malloc(sizeof(t_ls*) * (k + 1));
	while (flags[i] && flags[i][0] == '-' && ft_strcmp(flags[i], "--") &&
			flags[i][1] != '\0')
	{
		j = 0;
		while (flags[i][++j])
			if (ft_repeat_flags(flags[i][j], d, f) == 1)
			{
				f[d] = addlst(f[d]);
				f[d]->name[0] = flags[i][j];
				d++;
			}
		i++;
	}
	f[d] = 0;
	return (sortlist(f, 0, d - 1));
}

int		ft_repeat_flags(char c, int d, t_ls **new)
{
	int i;

	i = 0;
	if (d == 0)
		return (1);
	while (i < d)
	{
		while (new[i]->name[0] == c)
			return (0);
		i++;
	}
	return (1);
}

t_ls	**ft_parsing(char **str)
{
	t_ls	**pars;
	int		l;

	pars = NULL;
	if (!str)
		return (0);
	l = ft_check_flags_len(str);
	pars = ft_check_flags_lst(str, l);
	return (pars);
}
