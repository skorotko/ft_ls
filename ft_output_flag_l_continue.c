/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_flag_l_continue.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:25:39 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/09 13:25:40 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_time_flag_l(struct stat stbuf)
{
	char		*str_t;
	char		*str_time;
	long long	t_time_sec;

	t_time_sec = (stbuf.st_mtime - time(NULL));
	str_t = ctime(&stbuf.st_mtime);
	str_time = (char*)malloc(sizeof(char) * 13);
	str_time = ft_time_helper(str_time, str_t, t_time_sec);
	if (t_time_sec <= 999931122459 && t_time_sec >= 100000000000)
	{
		write(1, str_time, 13);
		free(str_time);
	}
	else
	{
		write(1, str_time, 12);
		free(str_time);
	}
	write(1, " ", 1);
}

void	ft_print_total_flag_l(t_ls **file, char *path, t_ls **fullpath)
{
	struct stat	stbuf;
	int			count;
	int			st_bloc;
	char		*save_strdup;
	char		*add_ful;

	count = -1;
	st_bloc = 0;
	if (!file[0] || (!lstat(path, &stbuf) && (S_ISLNK(stbuf.st_mode) ||
		S_ISREG(stbuf.st_mode))))
		return ;
	while (file[++count])
	{
		fullpath[0] = addlst(fullpath[0]);
		free(fullpath[0]->name);
		add_ful = ft_add_full(path, ft_strdup(file[count]->name), add_ful);
		fullpath[0]->name = add_ful;
		save_strdup = ft_strdup(file[count]->name);
		ft_strcat(fullpath[0]->name, save_strdup);
		free(save_strdup);
		lstat(fullpath[0]->name, &stbuf);
		st_bloc = st_bloc + stbuf.st_blocks;
		ft_twofree(fullpath[0], add_ful);
	}
	ft_pr_tot_help2(st_bloc);
}

void	ft_print_links_groups_names_size(struct stat stbuf, int *size_pading)
{
	struct passwd	*name;
	struct group	*group;

	write(1, "                     ",
		size_pading[0] - ft_intlen(stbuf.st_nlink));
	ft_putnbr(stbuf.st_nlink);
	write(1, " ", 1);
	name = getpwuid(stbuf.st_uid);
	write(1, name->pw_name, ft_strlen(name->pw_name));
	write(1, "                     ",
		(size_pading[1] - ft_strlen(name->pw_name)) + 2);
	group = getgrgid(stbuf.st_gid);
	write(1, group->gr_name, ft_strlen(group->gr_name));
	write(1, "                     ",
		size_pading[2] - ft_strlen(group->gr_name));
	write(1, "                     ",
		(size_pading[3] - ft_intlen(stbuf.st_size)) + 2);
	ft_print_size(stbuf);
	write(1, " ", 1);
}

void	ft_print_link_flag_l(char *file)
{
	char	save_link[PATH_MAX];
	ssize_t	link_count;

	link_count = readlink(file, save_link, PATH_MAX);
	save_link[link_count] = '\0';
	write(1, " -> ", 4);
	write(1, save_link, ft_strlen(save_link));
}

void	ft_print_size(struct stat stbuf)
{
	if (S_ISBLK(stbuf.st_mode) || S_ISCHR(stbuf.st_mode))
	{
		ft_putnbr(stbuf.st_rdev >> 24 & 0xff);
		write(1, ",    ", 4);
		ft_putnbr(stbuf.st_rdev & 0xffffff);
	}
	else
		ft_putnbr(stbuf.st_size);
}
