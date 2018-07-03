/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:05:23 by skorotko          #+#    #+#             */
/*   Updated: 2018/02/11 17:05:24 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_errors_files_or_directory_output(t_ls **err)
{
	int			i;
	struct stat	stbuf;

	i = -1;
	while (err[++i])
	{
		if (!lstat(err[i]->name, &stbuf) && S_ISLNK(stbuf.st_mode))
			continue;
		if (!ft_strcmp(err[i]->name, ""))
		{
			write(2, "ls: fts_open: No such file or directory\n", 41);
			exit(1);
		}
		write(2, "ls: ", 4);
		perror(err[i]->name);
	}
}

int		ft_putcharprint(char *std, int *save_pading)
{
	t_ls	**begin;
	int		i;
	int		q;

	i = 0;
	q = ft_readlength(std, 0);
	begin = sortlist(ft_readadd(q, std, 0), 0, q - 1);
	if (!begin)
		return (0);
	if (save_pading[0] >= 2 || save_pading[1] || save_pading[2])
		ft_try_output(std);
	while (i < q)
	{
		write(1, begin[i]->name, begin[i]->leng);
		ft_putchar('\n');
		i++;
	}
	if (save_pading[0] != save_pading[3])
		ft_putchar('\n');
	ft_array_list(begin);
	return (1);
}

int		ft_files_link_output(t_ls **files, t_ls **link, int length)
{
	t_ls	**join;
	int		i;
	int		z;

	join = ft_files_link_join(files, link);
	join = sortlist(join, 0, ft_count_list(join) - 1);
	z = ft_count_list(join);
	if (z == 0)
	{
		ft_help_output(files, link, join);
		return (0);
	}
	i = 0;
	while (join[i])
	{
		ft_putstr(join[i]->name);
		ft_putchar('\n');
		i++;
	}
	if (length > 0)
	{
		write(1, "\n", 1);
	}
	ft_help_output(files, link, join);
	return (1);
}

void	ft_files_directory_links_error(t_ls **direct)
{
	t_ls	**dir;
	t_ls	**err;
	int		save_pading[4];
	int		count;

	dir = ft_directory_check(direct);
	err = ft_error_check(direct);
	ft_errors_files_or_directory_output(err);
	save_pading[2] = ft_files_link_output(ft_files_check(direct),
		ft_links_check(err), ft_count_list(dir));
	save_pading[1] = 0;
	if (ft_count_list(err) > 0)
		save_pading[1] = 1;
	count = -1;
	while (dir[++count])
	{
		save_pading[0] = ft_count_list(dir);
		save_pading[3] = count + 1;
		if (!ft_putcharprint(dir[count]->name, save_pading))
		{
			ft_treatment_error_perm_denied(dir[count]->name, save_pading);
			continue;
		}
	}
	ft_help_free(err, dir);
}
