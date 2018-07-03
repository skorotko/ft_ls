/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pading_for_flag_l.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:15:50 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/09 13:15:52 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_length_pading_hard_link(t_ls **file, char *path)
{
	struct stat	stbuf;
	int			*length_pos;
	int			length_pos_count;
	t_ls		*fullpath[1];

	length_pos = (int*)malloc(sizeof(int) * (ft_count_list(file) + 1));
	length_pos_count = 0;
	while (file[length_pos_count])
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		stbuf = ft_pading_help(fullpath[0],
			file[length_pos_count]->name, path);
		length_pos[length_pos_count] = ft_intlen(stbuf.st_nlink);
		length_pos_count++;
		free(fullpath[0]);
	}
	length_pos[length_pos_count] = '\0';
	return (ft_max_len(length_pos));
}

int		ft_length_pading_size_files(t_ls **file, char *path)
{
	struct stat	stbuf;
	int			*length_pos;
	int			length_pos_count;
	t_ls		*fullpath[1];

	length_pos = (int*)malloc(sizeof(int) * (ft_count_list(file) + 1));
	length_pos_count = 0;
	while (file[length_pos_count])
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		stbuf = ft_pading_help(fullpath[0],
			file[length_pos_count]->name, path);
		length_pos[length_pos_count] = ft_intlen(stbuf.st_size);
		length_pos_count++;
		free(fullpath[0]);
	}
	length_pos[length_pos_count] = '\0';
	return (ft_max_len(length_pos));
}

int		ft_length_pading_size_group(t_ls **file, char *path)
{
	struct stat		stbuf;
	struct group	*group;
	t_ls			*fullpath[1];
	int				*length_pos;
	int				length_pos_count;

	length_pos = (int*)malloc(sizeof(int) * (ft_count_list(file) + 1));
	length_pos_count = 0;
	while (file[length_pos_count])
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		stbuf = ft_pading_help(fullpath[0],
			file[length_pos_count]->name, path);
		group = getgrgid(stbuf.st_gid);
		length_pos[length_pos_count] = ft_strlen(group->gr_name);
		length_pos_count++;
		free(fullpath[0]);
	}
	length_pos[length_pos_count] = '\0';
	return (ft_max_len(length_pos));
}

int		ft_length_pading_size_name(t_ls **file, char *path)
{
	struct stat		stbuf;
	struct passwd	*name;
	t_ls			*fullpath[1];
	int				*length_pos;
	int				length_pos_count;

	length_pos = (int*)malloc(sizeof(int) * (ft_count_list(file) + 1));
	length_pos_count = 0;
	while (file[length_pos_count])
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		stbuf = ft_pading_help(fullpath[0],
			file[length_pos_count]->name, path);
		name = getpwuid(stbuf.st_uid);
		length_pos[length_pos_count] = ft_strlen(name->pw_name);
		length_pos_count++;
		free(fullpath[0]);
	}
	length_pos[length_pos_count] = '\0';
	return (ft_max_len(length_pos));
}
