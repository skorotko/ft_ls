/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_flags_r.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:02:23 by skorotko          #+#    #+#             */
/*   Updated: 2018/02/26 19:02:25 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_err_fi_directory_out_flags_r(t_ls **err)
{
	int			i;
	struct stat	stbuf;

	i = -1;
	while (err[++i])
	{
		if (!lstat(err[i]->name, &stbuf) && S_ISLNK(stbuf.st_mode))
			continue ;
		if (!ft_strcmp(err[i]->name, ""))
		{
			write(2, "ls: fts_open: No such file or directory\n", 41);
			exit(2);
		}
		write(2, "ls: ", 4);
		perror(err[i]->name);
	}
}

int		ft_print_fl_r(char *std, int trigger, int *save_flags)
{
	t_ls	**begin;
	int		k;

	k = ft_readlength(std, save_flags[0]);
	if (save_flags[3] == 1)
		begin = ft_time_sort_st(ft_readadd(k, std, save_flags[0]), 0, k - 1);
	else
		begin = sortlist(ft_readadd(k, std, save_flags[0]), 0, k - 1);
	if (save_flags[2] == 1)
		r_sort_list(begin);
	if (!begin)
		return (0);
	if (trigger >= 2)
		ft_try_output_with_r(std);
	if (save_flags[1] == 1)
	{
		ft_start_flags_l(begin, std);
		ft_array_list(begin);
		return (1);
	}
	ft_print_fl_r_help(begin, k);
	ft_array_list(begin);
	return (1);
}

int		ft_f_l_out_fl_r(t_ls **files, t_ls **link, int length, int *save_flags)
{
	t_ls	**join;
	int		i;

	join = ft_files_link_join(files, link);
	if (save_flags[3] == 1)
		join = ft_time_sort_st(join, 0, ft_count_list(join) - 1);
	if (save_flags[2] == 1)
		r_sort_list(join);
	if (ft_count_list(join) == 0)
	{
		ft_array_list(join);
		return (0);
	}
	i = -1;
	while (join[++i])
	{
		ft_putstr(join[i]->name);
		ft_putchar('\n');
	}
	if (length > 0)
		write(1, "\n", 1);
	ft_array_list(join);
	return (1);
}

t_ls	**ft_links_files_check(t_ls **dir, int t)
{
	int			i;
	int			count;
	struct stat	stbuf;
	t_ls		**files;

	count = 0;
	files = NULL;
	i = -1;
	if (t == 1)
		dir = ft_time_sort_st(dir, 0, (ft_count_list(dir) - 1));
	while (dir[++i])
		if (!lstat(dir[i]->name, &stbuf) && (S_ISLNK(stbuf.st_mode) || \
			S_ISREG(stbuf.st_mode)))
		{
			ft_start_flags_l(dir, dir[i]->name);
			count++;
		}
	files = (t_ls**)malloc(sizeof(t_ls*) * ((i - count) + 1));
	files[i - count] = NULL;
	files = ft_links_files_check_help(dir, files);
	ft_array_list(dir);
	return (files);
}

void	ft_fi_di_li_err_fl_r(t_ls **direct, int *save_flags)
{
	t_ls		**dir;
	t_ls		**err;
	t_ls		**files;
	t_ls		**link;
	static int	trigger;

	dir = ft_directory_check(direct);
	err = ft_error_check(direct);
	files = ft_files_check(direct);
	link = ft_links_check(err);
	ft_err_fi_directory_out_flags_r(err);
	if (!save_flags[1])
		ft_f_l_out_fl_r(files, link,
			ft_count_list(dir), save_flags);
	dir = ft_dir_help(dir, save_flags);
	trigger = ft_l_f_help(err, direct, save_flags, trigger);
	ft_dir_help_cont(dir, save_flags, trigger);
	ft_array_list(err);
	ft_array_list(files);
	ft_array_list(link);
}
