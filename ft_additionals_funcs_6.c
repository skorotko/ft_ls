/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additionals_funcs_6.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:28:38 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/21 16:28:41 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_help_free(t_ls **str, t_ls **str1)
{
	ft_array_list(str);
	ft_array_list(str1);
}

char	*ft_helpdirw(char *begin, char *fullpath)
{
	char *save_strdup;

	save_strdup = ft_strdup(begin);
	ft_strcat(fullpath, save_strdup);
	free(save_strdup);
	return (fullpath);
}
