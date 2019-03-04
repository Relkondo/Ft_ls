/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:40:38 by scoron            #+#    #+#             */
/*   Updated: 2019/03/03 12:40:41 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdbool.h>
# include <time.h>


# define COLOUR		false
# define COLUMN		false

# define ALL_OPT		"ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1"
# define SIX_MONTHS		15768000
# define RL_BUFSIZE	1024
# define NUM_FILES	"--------------\nFiles: %d\n"
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

# define COL_REG	"\x1b[0m"
# define COL_DIR	"\x1b[1m\x1b[36m"
# define COL_IFO	"\x1b[33m"
# define COL_CHR	"\x1b[34;43m"
# define COL_BLK	"\x1b[34;46m"
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
		time_t			up_u_time;
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

typedef struct		s_args_ch
{	
		t_attr			attr;
		struct s_args	*next;
}					t_args_ch;

typedef struct			s_opt
{
		unsigned char	a;
		unsigned char	c;
		unsigned char	d;
		unsigned char	f;
		unsigned char	g;
		unsigned char	i;
		unsigned char	l;
		unsigned char	o;
		unsigned char	p;
		unsigned char	r;
		unsigned char	t;
		unsigned char	u;
		unsigned char	x;
		unsigned char	A;
		unsigned char	F;
		unsigned char	G;
		unsigned char	N;
		unsigned char	R;
		unsigned char	S;
		unsigned char	T;
		unsigned char	U;
		unsigned char	one;
}						t_opt;

typedef struct			s_lsbox
{
		char			**argv;
		char			**argv_opt;
		int				argc;
		time_t			now;
		time_t			six_months_ago;
		int				nb_opt;
		t_opt			opt;
		unsigned char	headers	: 1;
		unsigned char	fill	: 7;
		int				len_ino;
		int				len_links;
		int				len_user;
		int				len_group;
		int				len_size;
		int				len_file_name;
		int				items_to_display;
		int				total_blocks;
		int				width;
		int				number_of_columns;
		t_args_ch			*args;
		t_args_ch			*current_args;
		t_args_ch			*head;
		t_args_ch			*track;

		bool			(*sort_function)(struct s_frame *frame);
}						t_lsbox;

t_lsbox					init_lsbox(int argc, char **argv);
void					parsing(t_lsbox *lsbox);
int						main(int argc, char **argv);
void					opt_error(t_lsbox *lsbox, char c);
int						count_opt(t_lsbox *lsbox);
void					register_options(t_lsbox *lsbox);
void					free_lsbox(t_lsbox *lsbox);
void					ls_error(t_lsbox *lsbox, char *str);

#endif
