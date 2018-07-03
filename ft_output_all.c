/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:07:44 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 15:27:04 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_treatment_error_perm_denied(char *dir, int *save_pading)
{
	int d;
	int k;
	int q;

	k = 0;
	d = -1;
	q = 0;
	while (dir[++d])
		if (dir[d] == '/')
		{
			q = d;
			k++;
		}
	if (save_pading[0] == 1 && !save_pading[1] && !save_pading[2])
	{
		write(2, "ls: ", 4);
		if (k == 0)
			write(2, dir, ft_strlen(dir));
		write(2, ": Permission denied\n", 20);
	}
	if (save_pading[0] >= 2 || save_pading[1] || save_pading[2])
		ft_perm_help(dir, q + 1);
}

void	ft_err_perm_den_fl_r(char *dir, int count)
{
	int d;
	int k;
	int q;

	k = 0;
	d = -1;
	q = 0;
	while (dir[++d])
		if (dir[d] == '/')
		{
			q = d;
			k++;
		}
	if (count == 1)
	{
		write(2, "ls: ", 4);
		if (k == 0)
			write(2, dir, ft_strlen(dir));
		write(2, ": Permission denied\n", 20);
	}
	if (count >= 2)
		ft_perm_help(dir, q);
}

void	ft_perm_help(char *dir, int q)
{
	write(2, dir, ft_strlen(dir));
	write(2, ":\n", 2);
	write(2, "ls: ", 4);
	perror(dir + (q));
}
