/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:43:37 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/20 15:42:25 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_ls	**flags;
	t_ls	**direct;
	int		count_flags;

	argc = 0;
	flags = ft_parsing(argv);
	direct = ft_directory_save(argv);
	count_flags = ft_count_list(flags);
	if (!flags[0] || (count_flags == 1 && flags[0]->name[0] == '1'))
	{
		ft_files_directory_links_error(direct);
		ft_array_list(direct);
		ft_array_list_name(flags);
	}
	else
	{
		ft_star_function(direct, flags);
		ft_array_list(direct);
		ft_array_list_name(flags);
	}
	return (0);
}
