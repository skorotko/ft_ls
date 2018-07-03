/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:32:45 by skorotko          #+#    #+#             */
/*   Updated: 2018/01/30 17:48:53 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include "struct_ls.h"

void	ft_swaplist(t_ls **array, int swap_this, int with_that);
int		ft_readlength(char *std, int a);
int		ft_putcharprint(char *std, int *save_pading);
t_ls	**ft_readadd(int length, char *std, int a);
t_ls	*addlst(t_ls *new);
t_ls	**sortlist(t_ls **new, int start, int end);
int		ft_check_flags_len(char **flags);
t_ls	**ft_check_flags_lst(char **flags, int k);
void	ft_write_errors(char c);
int		ft_repeat_flags(char c, int d, t_ls **new);
int		ft_directory(char **direct, int len);
t_ls	**ft_directory_save(char **direct);
t_ls	**ft_parsing(char **str);
t_ls	**ft_error_check(t_ls **dir);
t_ls	**ft_directory_check(t_ls **dir);
t_ls	**ft_files_check(t_ls **dir);
t_ls	**ft_links_check(t_ls **dir);
void	ft_files_directory_links_error(t_ls **direct);
void	ft_errors_files_or_directory_output(t_ls **err);
t_ls	**ft_files_otput(t_ls **files, t_ls **link);
void	ft_try_output(char *std);
int		ft_files_link_output(t_ls **files, t_ls **link, int length);
int		ft_count_list(t_ls **count);
t_ls	**ft_files_link_join(t_ls **files, t_ls **link);
void	ft_treatment_error_perm_denied(char *dir, int *save_pading);
void	ft_dirwalk(char *path, int *save_flags);
char	*ft_add_full(char *path, char *tmp, char *fullpath);
void	ft_dw_recur(t_ls **begin, t_ls **fullpath, char *path, int *save_flags);
void	ft_star_function(t_ls **files, t_ls **flags);
void	ft_err_fi_directory_out_flags_r(t_ls **err);
int		ft_print_fl_r (char *std, int trigger, int *save_flags);
int		ft_f_l_out_fl_r(t_ls **files, t_ls **link, int length, int *save_flags);
void	ft_fi_di_li_err_fl_r(t_ls **direct, int *save_flags);
int		ft_count_char(char **str);
void	ft_start_dirwalk(t_ls **files, int *save_flags);
void	ft_start_flags_l(t_ls **file, char *path);
char	file_type(int mode);
void	rights_print(int mode, char *fullpath);
int		ft_intlen(int n);
int		ft_length_pading_hard_link(t_ls **file, char *path);
int		ft_max_len(int *str);
char	extend_or_acl(char *fullpath);
int		ft_length_pading_size_files(t_ls **file, char *path);
int		ft_length_pading_size_group(t_ls **file, char *path);
void	ft_print_time_flag_l(struct stat stbuf);
void	ft_print_total_flag_l(t_ls **file, char *path, t_ls **fullpath);
void	ft_print_links_groups_names_size(struct stat stbuf, int *size_pading);
void	ft_print_link_flag_l(char *file);
t_ls	**ft_links_files_check(t_ls **dir, int t);
t_ls	**ft_time_sortlist(t_ls **new, int start, int end);
t_ls	**ft_time_sortlist_ascii(t_ls **new);
t_ls	**r_sort_list(t_ls **direct);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
char	*ft_strcat(char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
int		ft_double_array_count(char **array);
void	ft_try_output_with_r(char *std);
int		ft_length_pading_size_name(t_ls **file, char *path);
void	ft_err_perm_den_fl_r(char *dir, int count);
t_ls	**ft_add_dot_in_empty(t_ls **dir);
t_ls	**ft_copy_struct(t_ls **dir, char **direct, int l);
t_ls	**ft_files_link_join_helper(t_ls **files, t_ls **link, t_ls **output);
t_ls	**ft_readadd_helper(t_ls **n, DIR *dir, char *std, int a);
char	*ft_time_helper(char *str_time, char *str_t, long long t_time_sec);
int		*ft_count_pading(t_ls **file, char *path, int count);
void	ft_print_size(struct stat stbuf);
void	ft_fl_l(t_ls **file, t_ls **fullpath, char *path, struct stat stbuf);
void	ft_start_dirwalk_cont(t_ls **dir, int check_list, int *save_flags);
t_ls	**ft_time_sort_st(t_ls **new, int start, int end);
int		ft_l_f_help(t_ls **err, t_ls **direct, int *save_flags, int trigger);
t_ls	**ft_dir_help(t_ls **dir, int *save_flags);
void	ft_dir_help_cont(t_ls **dir, int *save_flags, int trigger);
t_ls	**ft_links_files_check_help(t_ls **dir, t_ls **files);
void	ft_dw_recur_help(t_ls **fullpath, char *path, int *save_flags);
int		ft_dw_recur_help_2(t_ls **fullpath, int k, int *save_flags);
void	ft_array_list(t_ls **direct);
void	ft_double_array(char **direct);
void	ft_array_list_name(t_ls **direct);
t_ls	*addlst_2(t_ls *new);
void	ft_print_fl_r_help(t_ls **begin, int k);
void	ft_help(t_ls *full, char *add_f, char *path, struct stat stbuf);
void	ft_star_function_cont(t_ls **files, t_ls **flags, int *save_flags);
int		ft_pr_tot_help(char *full, int bloc, struct stat stbuf);
void	ft_pr_tot_help2(int st_bloc);
void	ft_l_f_help_free(t_ls **links_files, t_ls **links, t_ls **files);
void	ft_twofree(void *s1, void *s2);
void	ft_perm_help(char *dir, int q);
void	ft_help_output(t_ls **files, t_ls **link, t_ls	**join);
void	ft_help_free(t_ls **str, t_ls **str1);
char	*ft_helpdirw(char *begin, char *fullpath);
#endif
