/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:25:21 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/15 15:25:23 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	**ft_add_dot_in_empty(t_ls **dir)
{
	dir = (t_ls**)malloc(sizeof(t_ls*) * (2));
	dir[0] = addlst(dir[0]);
	free(dir[0]->name);
	dir[0]->name = ".";
	dir[1] = NULL;
	return (dir);
}

t_ls	**ft_copy_struct(t_ls **dir, char **direct, int l)
{
	int i;

	i = 0;
	while (direct[l])
	{
		dir[i] = addlst(dir[i]);
		free(dir[i]->name);
		dir[i]->name = direct[l];
		i++;
		l++;
	}
	dir[i] = 0;
	return (dir);
}
