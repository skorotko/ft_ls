/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pading_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:42:18 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 16:42:20 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct stat		ft_pading_help(t_ls *fullpath, char *file, char *path)
{
	struct stat	stbuf;
	char		*save_strdup;
	char		*add_fullpath;

	if (!lstat(path, &stbuf) &&
		(S_ISREG(stbuf.st_mode) || S_ISLNK(stbuf.st_mode)))
	{
		fullpath->name = ft_strdup(path);
		lstat(fullpath->name, &stbuf);
		free(fullpath->name);
	}
	else
	{
		add_fullpath = ft_add_full(path,
			ft_strdup(file), fullpath->name);
		fullpath->name = add_fullpath;
		save_strdup = ft_strdup(file);
		ft_strcat(fullpath->name, save_strdup);
		lstat(fullpath->name, &stbuf);
		free(save_strdup);
		free(add_fullpath);
	}
	return (stbuf);
}
