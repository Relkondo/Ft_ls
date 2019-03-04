
#ifndef TEMPO_H
# define TEMPO_H

void				read_f(t_lsbox *lsbox, t_args *args_ch, struct stat *func);
void				attributes(t_lsbox *lsbox);
void				calc_len_links(t_lsbox *lsbox, t_args_ch_ch *args);
void				calc_len_size(t_lsbox *lsbox, t_args_ch *args);
void				calc_len_user(t_lsbox *lsbox, t_args_ch *args);
void				calculate_number_of_columns(t_lsbox *lsbox);
bool				is_executeable(t_args_ch *args);
void				calc_len_file_name(t_lsbox *lsbox, t_args_ch *args);
void				calc_len_group(t_lsbox *lsbox, t_args_ch *args);
void				calc_len_ino(t_lsbox *lsbox, t_args_ch *args);
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
void				file_name(t_lsbox *lsbox, t_args_ch *args);
void				free(t_lsbox *lsbox, t_args_ch **head);
void				ls_loop(t_lsbox *lsbox, t_args_ch *args);
void				loop_files(t_lsbox *lsbox);
void				loop_no_file(t_lsbox *lsbox);
void				loop_dirs(t_lsbox *lsbox);
void				loop_init(t_lsbox *lsbox);
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
void				no_file(t_lsbox *lsbox, t_args_ch *args);
t_args_ch				*create_args(void);
bool				is_executeable(t_args_ch *args);
void				path(t_lsbox *lsbox, t_args_ch *args, char *path, char *name);
void				type(t_lsbox *lsbox, t_args_ch *args);

#endif
