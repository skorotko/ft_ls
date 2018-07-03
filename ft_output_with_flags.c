/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_with_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:36:01 by skorotko          #+#    #+#             */
/*   Updated: 2018/02/26 17:36:04 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_star_function(t_ls **files, t_ls **flags)
{
	int	g;
	int	s;
	int	f;
	int	save_flags[4];

	g = -1;
	f = -1;
	s = 0;
	while (++g < 4)
		save_flags[g] = 0;
	while (flags[++f])
	{
		if (flags[f]->name[0] == 'a')
			save_flags[0] = 1;
		if (flags[f]->name[0] == 'l')
			save_flags[1] = 1;
		if (flags[f]->name[0] == 'r')
			save_flags[2] = 1;
		if (flags[f]->name[0] == 't')
			save_flags[3] = 1;
	}
	ft_star_function_cont(files, flags, save_flags);
}

void	ft_star_function_cont(t_ls **files, t_ls **flags, int *save_flags)
{
	int g;

	g = 0;
	if (flags[0]->name[0] == '1')
		g = 1;
	if (flags[g]->name[0] == 'R')
		ft_start_dirwalk(files, save_flags);
	else
		ft_fi_di_li_err_fl_r(files, save_flags);
}

void	ft_start_dirwalk(t_ls **files, int *save_flags)
{
	t_ls	**dir;
	t_ls	**err;
	int		check_list;
	int		list;

	list = 0;
	files = sortlist(files, 0, ft_count_list(files) - 1);
	dir = ft_directory_check(files);
	err = ft_error_check(files);
	ft_err_fi_directory_out_flags_r(err);
	if (save_flags[1] == 0)
		list = ft_files_link_output(ft_files_check(files),
			ft_links_check(err), ft_count_list(dir));
	ft_l_f_help(err, files, save_flags, 0);
	check_list = ft_count_list(dir);
	if (err[0])
		check_list++;
	check_list = list + check_list;
	ft_start_dirwalk_cont(dir, check_list, save_flags);
	ft_array_list(err);
}

void	ft_start_dirwalk_cont(t_ls **dir, int check_list, int *save_flags)
{
	int	tmp;
	int	list;

	tmp = check_list;
	list = -1;
	if (save_flags[1] == 1)
		while (dir[++list])
		{
			if (check_list == tmp && check_list > 1)
				ft_try_output(dir[list]->name);
			tmp--;
			ft_dirwalk(dir[list]->name, save_flags);
		}
	else
		while (dir[++list])
		{
			if (check_list == tmp && check_list > 1)
				ft_try_output(dir[list]->name);
			tmp--;
			ft_dirwalk(dir[list]->name, save_flags);
		}
	ft_array_list(dir);
}
