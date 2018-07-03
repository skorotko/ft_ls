/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:32:47 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/19 17:03:13 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_dirwalk(char *path, int *save_flags)
{
	t_ls		**begin;
	t_ls		*fullpath[2];

	fullpath[1] = NULL;
	begin = NULL;
	if (save_flags[3] == 1)
		begin = ft_time_sort_st(ft_readadd(ft_readlength(path, save_flags[0]),
			path, save_flags[0]), 0, ft_readlength(path, save_flags[0]) - 1);
	else
		begin = sortlist(ft_readadd(ft_readlength(path, save_flags[0]), \
			path, save_flags[0]), 0, ft_readlength(path, save_flags[0]) - 1);
	if (save_flags[2] == 1)
		r_sort_list(begin);
	if (begin == NULL)
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		fullpath[0]->name = path;
		ft_fi_di_li_err_fl_r(fullpath, save_flags);
		free(fullpath[0]);
		return ;
	}
	ft_dw_recur(begin, fullpath, path, save_flags);
	ft_array_list(begin);
}

void	ft_dw_recur(t_ls **begin, t_ls **fullpath, char *path, int *save_flags)
{
	int			k[2];
	struct stat	stbuf;
	char		*add_full;

	k[0] = 0;
	k[1] = -1;
	while (begin[++k[1]])
	{
		if (ft_strcmp(begin[k[1]]->name, ".") == 0 || \
				ft_strcmp(begin[k[1]]->name, "..") == 0)
			continue ;
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		add_full = ft_add_full(path, ft_strdup(begin[k[1]]->name), add_full);
		fullpath[0]->name = add_full;
		if (k[0] == 0)
			k[0] = ft_dw_recur_help_2(fullpath, k[0], save_flags);
		fullpath[0]->name = ft_helpdirw(begin[k[1]]->name, fullpath[0]->name);
		if ((!stat(fullpath[0]->name, &stbuf) && S_ISDIR(stbuf.st_mode)) && \
			(!lstat(fullpath[0]->name, &stbuf) && !S_ISLNK(stbuf.st_mode)))
			ft_dirwalk(fullpath[0]->name, save_flags);
		ft_twofree(add_full, fullpath[0]);
	}
	if ((ft_count_list(begin) == 2 && save_flags[0]) || !ft_count_list(begin))
		ft_dw_recur_help(fullpath, path, save_flags);
}

void	ft_dw_recur_help(t_ls **fullpath, char *path, int *save_flags)
{
	char	*dup;

	fullpath[0] = addlst(fullpath[0]);
	free(fullpath[0]->name);
	dup = ft_strdup(path);
	fullpath[0]->name = dup;
	ft_fi_di_li_err_fl_r(fullpath, save_flags);
	free(dup);
	free(fullpath[0]);
}

int		ft_dw_recur_help_2(t_ls **fullpath, int k, int *save_flags)
{
	ft_fi_di_li_err_fl_r(fullpath, save_flags);
	k++;
	return (k);
}

char	*ft_add_full(char *path, char *tmp, char *fullpath)
{
	struct stat	stbuf;

	fullpath = (char*)malloc(sizeof(char)\
		* ((ft_strlen(path) + ft_strlen(tmp)) + 2));
	ft_strcpy(fullpath, path);
	if (fullpath[ft_strlen(path + 1)] != '/' && (lstat(path, &stbuf) == 0 && \
		(S_ISLNK(stbuf.st_mode) != 1)))
		fullpath[ft_strlen(path)] = '/';
	fullpath[ft_strlen(path) + 1] = '\0';
	free(tmp);
	return (fullpath);
}
