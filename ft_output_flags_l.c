/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_flags_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:22:08 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 15:06:16 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_start_flags_l(t_ls **file, char *path)
{
	struct stat	stbuf;
	t_ls		*fullpath[2];
	char		*add_fullpath;

	fullpath[1] = NULL;
	ft_print_total_flag_l(file, path, fullpath);
	if (!lstat(path, &stbuf) && (S_ISLNK(stbuf.st_mode) ||
				S_ISREG(stbuf.st_mode)))
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		add_fullpath = ft_add_full(path, \
				ft_strdup(file[0]->name), fullpath[0]->name);
		fullpath[0]->name = add_fullpath;
		rights_print(stbuf.st_mode, fullpath[0]->name);
		ft_print_links_groups_names_size(stbuf,
			ft_count_pading(file, path, 0));
		ft_print_time_flag_l(stbuf);
		write(1, path, ft_strlen(path));
		ft_help(fullpath[0], add_fullpath, path, stbuf);
		return ;
	}
	if (file[0])
		ft_fl_l(file, fullpath, path, stbuf);
}

void	ft_fl_l(t_ls **file, t_ls **fullpath, char *path, struct stat stbuf)
{
	int		count;
	char	*save_strdup;
	char	*add_fullpath;

	count = -1;
	while (file[++count])
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		add_fullpath = ft_add_full(path, \
				ft_strdup(file[count]->name), fullpath[0]->name);
		fullpath[0]->name = add_fullpath;
		save_strdup = ft_strdup(file[count]->name);
		ft_strcat(fullpath[0]->name, save_strdup);
		free(save_strdup);
		if (lstat(fullpath[0]->name, &stbuf) != 0)
			return ;
		rights_print(stbuf.st_mode, fullpath[0]->name);
		ft_print_links_groups_names_size(stbuf,
			ft_count_pading(file, path, count));
		ft_print_time_flag_l(stbuf);
		write(1, file[count]->name, file[count]->leng);
		ft_help(fullpath[0], add_fullpath, fullpath[0]->name, stbuf);
	}
}

char	file_type(int mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

void	rights_print(int mode, char *fullpath)
{
	char	rights[12];

	rights[0] = file_type(mode);
	rights[1] = (S_IRUSR & mode) ? 'r' : '-';
	rights[2] = (S_IWUSR & mode) ? 'w' : '-';
	rights[3] = (S_IXUSR & mode) ? 'x' : '-';
	rights[4] = (S_IRGRP & mode) ? 'r' : '-';
	rights[5] = (S_IWGRP & mode) ? 'w' : '-';
	rights[6] = (S_IXGRP & mode) ? 'x' : '-';
	rights[7] = (S_IROTH & mode) ? 'r' : '-';
	rights[8] = (S_IWOTH & mode) ? 'w' : '-';
	rights[9] = (S_IXOTH & mode) ? 'x' : '-';
	rights[10] = (extend_or_acl(fullpath));
	rights[11] = '\0';
	if (S_ISUID & mode)
		rights[3] = rights[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		rights[6] = rights[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		rights[9] = rights[9] == '-' ? 'T' : 't';
	write(1, rights, 11);
}

char	extend_or_acl(char *fullpath)
{
	char	buf[101];
	acl_t	tmp;

	if (listxattr(fullpath, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(fullpath, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}
