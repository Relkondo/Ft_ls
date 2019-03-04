
#ifndef TEMPO_H
# define TEMPO_H

void				attributes(t_lsbox *lsbox);
void				calc_len_links(t_lsbox *lsbox, t_args *args);
void				calc_len_size(t_lsbox *lsbox, t_args *args);
void				calc_len_user(t_lsbox *lsbox, t_args *args);
void				calculate_number_of_columns(t_lsbox *lsbox);
bool				is_executeable(t_args *args);
void				calc_len_file_name(t_lsbox *lsbox, t_args *args);
void				calc_len_group(t_lsbox *lsbox, t_args *args);
void				calc_len_ino(t_lsbox *lsbox, t_args *args);
void				config_opts(t_lsbox *lsbox);
void				links(t_lsbox *lsbox, t_args *args);
void				ino(t_lsbox *lsbox, t_args *args);
void				user_and_group(t_lsbox *lsbox, t_args *args);
void				size(t_lsbox *lsbox, t_args *args);
void				display(t_lsbox *lsbox, t_args *args);
void				print_path(t_lsbox *lsbox, t_args *args, bool do_print);
void				print_spaces(int diff);
int				get_diff(t_lsbox *lsbox, char *str, long long num, int flag);
void				show_time(t_lsbox *lsbox, t_args *args);
void				file_name(t_lsbox *lsbox, t_args *args);
void				free_args(t_lsbox *lsbox, t_args **head);
void				free_ls(t_lsbox *lsbox);
void				ls_loop(t_lsbox *lsbox, t_args *args);
void				loop_files(t_lsbox *lsbox);
void				loop_no_file(t_lsbox *lsbox);
void				loop_dirs(t_lsbox *lsbox);
void				loop_init(t_lsbox *lsbox);
tatic void				reset_lengths(t_lsbox *lsbox);
void				loop_valid_dir(t_lsbox *lsbox, t_args *head);
t_lsbox				init_lsbox(int argc, char **argv);
void				parsing(t_lsbox *lsbox);
int				main(int argc, char **argv);
void				opt_error(t_lsbox *lsbox, char c);
int				count_opt(t_lsbox *lsbox);
void				fetch(t_lsbox *lsbox, char c);
void				init_fetch(t_lsbox *lsbox);
void				register_opts(t_lsbox *lsbox);
void				sort(t_lsbox *lsbox);
void				assign_sort(t_lsbox *lsbox);
bool				sort_alpha(t_lsbox *lsbox);
bool				sort_size(t_lsbox *lsbox);
bool				sort_time(t_lsbox *lsbox);
bool				sort_alpha_r(t_lsbox *lsbox);
bool				sort_size_r(t_lsbox *lsbox);
bool				sort_time_r(t_lsbox *lsbox);
void				config_opts(t_lsbox *lsbox);
void				ls_error(t_lsbox *lsbox, char *str);
void				no_file(t_lsbox *lsbox, t_args *args);
t_args				*create_args(void);
bool				is_executeable(t_args *args);
void				path(t_lsbox *lsbox, t_args *args, char *path, char *name);
void				type(t_lsbox *lsbox, t_args *args);

#endif
