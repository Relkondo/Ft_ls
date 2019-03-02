#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <stdbool.h>
# include <time.h>


# define ALL_OPT		"ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1"
# define SIX_MONTHS		15768000

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
		char				**argv;
		char				**argv_opt;
		char				argc;
		time_t				now;
		time_t				six_months_ago;
		int					nb_opt;
		t_opt				opt;
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
