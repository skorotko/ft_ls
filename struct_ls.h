/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ls.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:20:25 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/21 17:20:30 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LS_H
# define STRUCT_LS_H

typedef struct		s_ls
{
	int				leng;
	long long		time;
	char			*name;
	char			*name_tmp;
}					t_ls;

struct stat			ft_pading_help(t_ls *fullpath, char *file, char *path);
#endif
