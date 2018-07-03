/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionals_funcs_5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:42:28 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 17:42:29 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_pr_tot_help(char *full, int bloc, struct stat stbuf)
{
	lstat(full, &stbuf);
	bloc = bloc + stbuf.st_blocks;
	free(full);
	return (bloc);
}

void	ft_pr_tot_help2(int st_bloc)
{
	write(1, "total ", 6);
	ft_putnbr(st_bloc);
	write(1, "\n", 1);
}

void	ft_l_f_help_free(t_ls **links_files, t_ls **links, t_ls **files)
{
	ft_array_list(links_files);
	ft_array_list(links);
	ft_array_list(files);
}

void	ft_twofree(void *s1, void *s2)
{
	free(s1);
	free(s2);
}

void	ft_help_output(t_ls **files, t_ls **link, t_ls **join)
{
	ft_array_list(files);
	ft_array_list(link);
	ft_array_list(join);
}
