/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionals_funcs_4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:25:54 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 16:03:58 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_l_f_help(t_ls **err, t_ls **direct, int *save_flags, int trigger)
{
	t_ls	**links_files;
	t_ls	**links;
	t_ls	**files;
	int		i;

	i = -1;
	links_files = NULL;
	links = ft_links_check(err);
	files = ft_files_check(direct);
	links_files = ft_files_link_join(files, links);
	links_files = sortlist(links_files, 0, ft_count_list(links_files) - 1);
	if (save_flags[3] == 1)
		links_files = ft_time_sort_st(links_files, 0,
			(ft_count_list(links_files) - 1));
	if (save_flags[2] == 1)
		r_sort_list(links_files);
	if (links_files && save_flags[1] == 1)
		while (links_files[++i])
		{
			trigger++;
			ft_start_flags_l(links_files, links_files[i]->name);
		}
	ft_l_f_help_free(links_files, links, files);
	return (trigger);
}

t_ls	**ft_dir_help(t_ls **dir, int *save_flags)
{
	struct stat	stbuf;
	int			i;

	if (save_flags[3] == 1)
		dir = ft_time_sort_st(dir, 0, (ft_count_list(dir) - 1));
	if (save_flags[2] == 1)
		r_sort_list(dir);
	i = -1;
	while (dir[++i])
		if (!lstat(dir[i]->name, &stbuf) &&
			(S_ISLNK(stbuf.st_mode) || S_ISREG(stbuf.st_mode)))
			continue;
	dir = ft_links_files_check(dir, save_flags[3]);
	return (dir);
}

void	ft_dir_help_cont(t_ls **dir, int *save_flags, int trigger)
{
	int			i;
	static int	count;

	i = -1;
	count = count + trigger;
	while (dir[++i])
	{
		if (count >= 1)
			ft_putchar('\n');
		if (ft_count_list(dir) > 1)
			count++;
		count += 1;
		if (dir[i] && !ft_print_fl_r(dir[i]->name, count, save_flags))
		{
			ft_err_perm_den_fl_r(dir[i]->name, count);
			continue;
		}
	}
	ft_array_list(dir);
}

t_ls	**ft_links_files_check_help(t_ls **dir, t_ls **files)
{
	int			i;
	int			count;
	struct stat	stbuf;

	i = -1;
	count = 0;
	while (dir[++i])
	{
		if (!lstat(dir[i]->name, &stbuf) && (S_ISLNK(stbuf.st_mode) ||
			S_ISREG(stbuf.st_mode)))
			continue;
		else
		{
			files[count] = addlst(files[count]);
			free(files[count]->name);
			files[count]->name = dir[i]->name;
			count++;
		}
	}
	return (files);
}

void	ft_help(t_ls *full, char *add_f, char *path, struct stat stbuf)
{
	if (S_ISLNK(stbuf.st_mode))
		ft_print_link_flag_l(path);
	ft_putchar('\n');
	free(add_f);
	free(full);
}
