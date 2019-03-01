#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"

# define BUF_SIZE 90
# define F_SHARP		(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS			(1 << 2)
# define F_MINUS		(1 << 3)
# define F_ZERO			(1 << 4)
# define F_PREZERO		(1 << 5)
# define F_UPCASE		(1 << 6)
# define F_SHORT		(1 << 7)
# define F_LONG			(1 << 8)
# define F_LONG2		(1 << 9)
# define F_CHAR			(1 << 10)
# define F_INTMAX		(1 << 11)
# define F_SIZET		(1 << 12)
# define F_PRECI		(1 << 13)

typedef struct		s_lsbox
{
	char			**argv;
	char			**argv_opt;
	char			argc;
	time_t			now;
	time_t			6m_ago;
	char			*nomalloc;
	int				nb_opt;
}					t_lsbox;

void				print_do(t_ftp *p, long double flt);

#endif
