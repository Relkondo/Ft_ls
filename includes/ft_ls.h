/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:40:38 by scoron            #+#    #+#             */
/*   Updated: 2019/03/14 12:20:12 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "printf.h"
# include <dirent.h>
# include <stdbool.h>
# include <time.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>

# define COLOUR		false
# define COLUMN		false
# define ALL_OPT	"-ABCFGHLNOPRSTUWabcdefghiklmnopqrstuwx1@"
# define SIX_MONTHS	15768000
# define RL_BUFSIZE	1024
# define NUM_FILES	"--------------\nFiles:\n%d"
# define CHRSIZELEN	8
# define LEN_INO	1
# define LEN_LINKS	2
# define LEN_USER	3
# define LEN_GROUP	4
# define LEN_SIZE	5
# define LEN_SIZE_C	6
# define LEN_NAME	7
# define PER_LEN	11
# define PER_BLK	'b'
# define PER_CHR	'c'
# define PER_DIR	'd'
# define PER_LNK	'l'
# define PER_SOCK	's'
# define PER_IFO	'p'
# define PER_REG	'-'
# define PER_N		"-"
# define PER_R		"r"
# define PER_W		"w"
# define PER_X		"x"
# define PER_0		PER_N PER_N PER_N
# define PER_1		PER_N PER_N PER_X
# define PER_2		PER_N PER_W PER_N
# define PER_3		PER_N PER_W PER_X
# define PER_4		PER_R PER_N PER_N
# define PER_5		PER_R PER_N PER_X
# define PER_6		PER_R PER_W PER_N
# define PER_7		PER_R PER_W PER_X
# define TYPE_IFO	010000
# define TYPE_CHR	020000
# define TYPE_DIR	040000
# define TYPE_BLK	060000
# define TYPE_REG	0100000
# define TYPE_LNK	0120000
# define TYPE_SOCK	0140000
# define TYPE_WHT	0160000
# define COL_IFO	"\x1b[33m"
# define COL_CHR	"\x1b[34;43m"
# define COL_DIR	"\x1b[1m\x1b[36m"
# define COL_BLK	"\x1b[34;46m"
# define COL_REG	"\x1b[0m"
# define COL_LNK	"\x1b[35m"
# define COL_SOCK	"\x1b[32m"
# define COL_WHT	"\x1b[31m"
# define COL_EXE	"\x1b[31m"
# define COL_CLR	"\x1b[0m"

typedef struct		s_attr
{
	char			*str;
	char			*path;
	int				len_of_str;
	unsigned char	no_file	: 1;
	unsigned char	fill	: 7;
	long long		ino;
	int				type;
	mode_t			mode;
	int				links;
	char			*user;
	char			*group;
	int				rdev;
	int				size;
	time_t			c_time;
	time_t			t_time;
	time_t			u_time;
	time_t			cap_u_time;
	char			sym_path[RL_BUFSIZE + 1];
	unsigned char	ifo		: 1;
	unsigned char	chr		: 1;
	unsigned char	dir		: 1;
	unsigned char	blk		: 1;
	unsigned char	reg		: 1;
	unsigned char	lnk		: 1;
	unsigned char	sock	: 1;
	unsigned char	wht		: 1;
}					t_attr;

typedef struct		s_args
{
	t_attr			attr;
	struct s_args	*next;
}					t_args;

typedef struct		s_opt
{
	unsigned char	a		: 1;
	unsigned char	c		: 1;
	unsigned char	d		: 1;
	unsigned char	f		: 1;
	unsigned char	g		: 1;
	unsigned char	i		: 1;
	unsigned char	l		: 1;
	unsigned char	o		: 1;
	unsigned char	p		: 1;
	unsigned char	r		: 1;
	unsigned char	t		: 1;
	unsigned char	u		: 1;
	unsigned char	x		: 1;
	unsigned char	cap_a	: 1;
	unsigned char	cap_f	: 1;
	unsigned char	cap_g	: 1;
	unsigned char	cap_n	: 1;
	unsigned char	cap_r	: 1;
	unsigned char	cap_s	: 1;
	unsigned char	cap_t	: 1;
	unsigned char	cap_u	: 1;
	unsigned char	one		: 1;
	unsigned char	at		: 1;
}					t_opt;

typedef struct		s_lsbox
{
	char			**argv;
	char			**argv_opt;
	int				argc;
	time_t			now;
	time_t			six_months_ago;
	int				nb_opt;
	t_opt			opt;
	unsigned char	headers	: 1;
	int				len_ino;
	int				len_links;
	int				len_user;
	int				len_group;
	int				len_size;
	int				len_file_name;
	int				items_to_display;
	int				total_blocks;
	int				width;
	int				nb_columns;
	t_args			*args;
	t_args			*current_args;
	t_args			*head;
	t_args			*track;
	int				(*sort_func)(struct s_lsbox *lsbox);
}					t_lsbox;

typedef struct		s_read_dir
{
	t_lsbox			*lsbox;
	t_args			*args;
	t_args			*tmp;
	t_args			*head;
	t_args			*last_args;
	DIR				*directory;
	struct dirent	*file;
}					t_read_dir;

bool				is_executeable(t_args *args);
void				calc_len_file_name(t_lsbox *lsbox, t_args *args);
void				calc_len_ino(t_lsbox *lsbox, t_args *args);
void				calc_nb_col(t_lsbox *lsbox);
void				calc_len_links(t_lsbox *lsbox, t_args *args);
void				calc_len_size(t_lsbox *lsbox, t_args *args);
void				calc_len_user(t_lsbox *lsbox, t_args *args);
void				calc_len_group(t_lsbox *lsbox, t_args *args);
void				links(t_lsbox *lsbox, t_args *args);
void				ino(t_lsbox *lsbox, t_args *args);
void				user_and_group(t_lsbox *lsbox, t_args *args);
void				size(t_lsbox *lsbox, t_args *args);
void				display(t_lsbox *lsbox, t_args *args);
void				print_path(t_lsbox *lsbox, t_args *args, bool do_print);
void				d_space(int diff);
int					get_diff(t_lsbox *lsbox, char *str,
					long long num, int flag);
void				d_time(t_lsbox *lsbox, t_args *args);
void				d_file_name(t_lsbox *lsbox, t_args *args);
void				free_args(t_lsbox *lsbox, t_args **head);
void				free_ls(t_lsbox *lsbox);
void				ls_error(t_lsbox *lsbox, char *str);
void				ls_loop(t_lsbox *lsbox, t_args *args);
void				loop_in_dir(t_lsbox *lsbox, t_args *head);
void				loop_in_dir(t_lsbox *lsbox, t_args *head);
void				no_file(t_lsbox *lsbox, t_args *args);
void				loop_no_file(t_lsbox *lsbox);
void				loop_root_dirs(t_lsbox *lsbox);
void				loop_init(t_lsbox *lsbox);
void				loop_root_files(t_lsbox *lsbox);
int					main(int argc, char **argv);
void				assign_sort(t_lsbox *lsbox);
void				opt_effect(t_lsbox *lsbox);
t_args				*add_args_element(void);
void				register_args(t_lsbox *lsbox, char **argv);
void				read_f(t_lsbox *lsbox, t_args *args, struct stat *st_attr);
void				register_attr(t_lsbox *lsbox);
void				opt_error(t_lsbox *lsbox, char c);
int					count_opt(t_lsbox *lsbox);
void				fetch(t_lsbox *lsbox, char c);
void				init_fetch(t_lsbox *lsbox);
void				register_opts(t_lsbox *lsbox);
void				path(t_lsbox *lsbox, t_args *args, char *path, char *name);
void				sort(t_lsbox *lsbox);
int					sort_alpha(t_lsbox *lsbox);
int					sort_size(t_lsbox *lsbox);
int					sort_time(t_lsbox *lsbox);
int					sort_time_r(t_lsbox *lsbox);
void				d_type(t_lsbox *lsbox, t_args *args);

#endif
