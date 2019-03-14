/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:24:04 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 13:08:29 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

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

typedef struct		s_ftp
{
	char			*format;
	va_list			va;
	char			*buf;
	int				fd;
	int				len_buf;
	int				n;
	int				f;
	size_t			preci;
	int				min;
	int				padding;
	int				size;
	int				retv;
	intmax_t		val;
	uintmax_t		u_val;
}					t_ftp;

void				parse_options(t_ftp *p);
void				buffer(t_ftp *p, int n, char *str);
void				cs_int(t_ftp *p, char c);
void				cs_char(t_ftp *p, char c);
void				cs_str(t_ftp *p, char c);
void				cs_point(t_ftp *p, char c);
void				cs_float(t_ftp *p, char c);
int					ft_printf(char *format, ...);
void				padding(t_ftp *p, char c);
uintmax_t			ft_uarg(t_ftp *p);
intmax_t			ft_arg(t_ftp *p);
int					size_nu(t_ftp *p, intmax_t n);
int					size_ba(t_ftp *p, uintmax_t n, char c);
int					size_do(t_ftp *p, long double flt);
void				print_nu(t_ftp *p, intmax_t n);
void				print_ba(t_ftp *p, uintmax_t n, char *base, char c);
void				print_do(t_ftp *p, long double flt);

#endif
