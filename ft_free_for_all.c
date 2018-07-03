/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_for_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:08:12 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/16 17:08:14 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_array_list(t_ls **direct)
{
	int count;

	count = -1;
	while (direct[++count])
	{
		free(direct[count]->name_tmp);
		free(direct[count]);
	}
	free(direct);
}

void	ft_array_list_name(t_ls **direct)
{
	int count;

	count = -1;
	while (direct[++count])
	{
		free(direct[count]->name);
		free(direct[count]);
	}
	free(direct);
}

void	ft_double_array(char **direct)
{
	int count;

	count = -1;
	while (direct[++count])
		free(direct[count]);
	free(direct);
}
