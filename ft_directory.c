/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:32:56 by skorotko          #+#    #+#             */
/*   Updated: 2018/02/09 15:32:59 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	**ft_directory_save(char **direct)
{
	int		i;
	int		l;
	int		len;
	t_ls	**dir;

	len = 1;
	i = 0;
	dir = NULL;
	while (direct[len] && direct[len][0] == '-' && \
		ft_strcmp(direct[len], "--") && direct[len][1] != '\0')
		len++;
	if (!direct[len] || (!ft_strcmp(direct[len], "--") && !direct[len + 1] && \
			ft_double_array_count(direct + len) == 1))
		return (ft_add_dot_in_empty(dir));
	if (direct[len][0] == '-' && direct[len][1] == '-')
		len++;
	l = len;
	while (direct[len++])
		i++;
	dir = (t_ls**)malloc(sizeof(t_ls*) * (i + 1));
	return (ft_copy_struct(dir, direct, l));
}

t_ls	**ft_error_check(t_ls **dir)
{
	struct stat	stbuf;
	t_ls		**err;
	int			i;
	int			e;

	e = 0;
	i = -1;
	while (dir[++i])
		if (stat(dir[i]->name, &stbuf) == -1)
			e++;
	err = (t_ls**)malloc(sizeof(t_ls*) * (e + 1));
	e = 0;
	i = -1;
	while (dir[++i])
		if (stat(dir[i]->name, &stbuf) == -1)
		{
			err[e] = addlst(err[e]);
			free(err[e]->name);
			err[e]->name = dir[i]->name;
			e++;
		}
	err[e] = 0;
	return (sortlist(err, 0, e - 1));
}

t_ls	**ft_directory_check(t_ls **dir)
{
	struct stat	stbuf;
	t_ls		**direct;
	int			i;
	int			d;

	d = 0;
	i = -1;
	while (dir[++i])
		if (!stat(dir[i]->name, &stbuf) && S_ISDIR(stbuf.st_mode))
			d++;
	direct = (t_ls**)malloc(sizeof(t_ls*) * (d + 1));
	d = 0;
	i = -1;
	while (dir[++i])
		if (!stat(dir[i]->name, &stbuf) && S_ISDIR(stbuf.st_mode))
		{
			direct[d] = addlst(direct[d]);
			free(direct[d]->name);
			direct[d]->name = dir[i]->name;
			d++;
		}
	direct[d] = 0;
	return (sortlist(direct, 0, d - 1));
}

t_ls	**ft_files_check(t_ls **dir)
{
	struct stat	stbuf;
	t_ls		**files;
	int			i;
	int			f;

	f = 0;
	i = -1;
	while (dir[++i])
		if (!stat(dir[i]->name, &stbuf) && S_ISREG(stbuf.st_mode))
			f++;
	files = (t_ls**)malloc(sizeof(t_ls*) * (f + 1));
	f = 0;
	i = -1;
	while (dir[++i])
		if (!stat(dir[i]->name, &stbuf) && S_ISREG(stbuf.st_mode))
		{
			files[f] = addlst(files[f]);
			free(files[f]->name);
			files[f]->name = dir[i]->name;
			f++;
		}
	files[f] = 0;
	return (sortlist(files, 0, f - 1));
}

t_ls	**ft_links_check(t_ls **dir)
{
	struct stat	stbuf;
	t_ls		**links;
	int			i;
	int			l;

	l = 0;
	i = -1;
	while (dir[++i])
		if (!lstat(dir[i]->name, &stbuf) && S_ISLNK(stbuf.st_mode))
			l++;
	links = (t_ls**)malloc(sizeof(t_ls*) * (l + 1));
	l = 0;
	i = -1;
	while (dir[++i])
		if (!lstat(dir[i]->name, &stbuf) && S_ISLNK(stbuf.st_mode))
		{
			links[l] = addlst(links[l]);
			free(links[l]->name);
			links[l]->name = dir[i]->name;
			l++;
		}
	links[l] = 0;
	return (sortlist(links, 0, l - 1));
}
