/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionals_funcks_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:46:09 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 15:57:41 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	**ft_files_link_join_helper(t_ls **files, t_ls **link, t_ls **output)
{
	struct stat	stbuf;
	int			i;
	int			z;

	i = -1;
	z = -1;
	while (files[++i] != NULL)
	{
		output[i] = addlst(output[i]);
		free(output[i]->name);
		output[i]->name = files[i]->name;
		if (!lstat(files[i]->name, &stbuf))
			output[i]->time = (stbuf.st_mtime);
	}
	while (link[++z] != NULL)
	{
		output[i] = addlst(output[i]);
		free(output[i]->name);
		output[i]->name = link[z]->name;
		if (!lstat(link[z]->name, &stbuf))
			output[i]->time = (stbuf.st_mtime);
		i++;
	}
	output[i] = 0;
	return (output);
}

t_ls	**ft_readadd_helper(t_ls **n, DIR *dir, char *std, int a)
{
	struct dirent	*entry;
	struct stat		stbuf;
	int				length;
	char			*fullpath;
	char			*entry_dup;

	length = 0;
	while ((entry = readdir(dir)) != NULL)
	{
		if ((entry->d_name[0] == '.' || !ft_strcmp(entry->d_name, "..")) && !a)
			continue ;
		n[length] = addlst(n[length]);
		n[length]->name_tmp = ft_strdup(entry->d_name);
		free(n[length]->name);
		n[length]->name = n[length]->name_tmp;
		n[length]->leng = ft_strlen(n[length]->name);
		fullpath = ft_add_full(std, ft_strdup(entry->d_name), fullpath);
		entry_dup = ft_strdup(entry->d_name);
		ft_strcat(fullpath, entry_dup);
		if (!lstat(fullpath, &stbuf))
			n[length]->time = (stbuf.st_mtime);
		ft_twofree(entry_dup, fullpath);
		length++;
	}
	return (n);
}

char	*ft_time_helper(char *str_time, char *str_t, long long t_time_sec)
{
	int	count_time;
	int	count_t;

	count_time = 3;
	count_t = -1;
	if (t_time_sec <= 999931122459 && t_time_sec >= 100000000000)
		while (++count_time < 29)
		{
			if (count_time > 10 && count_time < 23)
				continue ;
			str_time[++count_t] = str_t[count_time];
		}
	else if (t_time_sec <= -15811200 || t_time_sec >= 15811200)
		while (++count_time < 25)
		{
			if (count_time > 10 && count_time < 19)
				continue ;
			str_time[++count_t] = str_t[count_time];
		}
	while (++count_time < 16)
		str_time[++count_t] = str_t[count_time];
	return (str_time);
}

int		*ft_count_pading(t_ls **file, char *path, int count)
{
	static int	size_pading[4];

	if (count == 0)
	{
		size_pading[0] = ft_length_pading_hard_link(file, path) + 1;
		size_pading[1] = ft_length_pading_size_name(file, path);
		size_pading[2] = ft_length_pading_size_group(file, path);
		size_pading[3] = ft_length_pading_size_files(file, path);
	}
	return (size_pading);
}

void	ft_print_fl_r_help(t_ls **begin, int k)
{
	int i;

	i = -1;
	while (++i < k)
	{
		write(1, begin[i]->name, begin[i]->leng);
		write(1, "\n", 1);
	}
}
