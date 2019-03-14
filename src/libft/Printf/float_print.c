/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:52:30 by scoron            #+#    #+#             */
/*   Updated: 2019/02/11 13:58:31 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putdouble(char *res, long long itg, int dot, t_ftp *p)
{
	long long		tmp;
	size_t			len;

	tmp = itg;
	len = itg == 0 ? p->preci + 1 : 1;
	while (tmp /= 10)
		len++;
	dot == 0 ? 0 : (len += 1);
	res[len] = '\0';
	while (len > 0)
	{
		if (dot && (int)len == dot + 1)
			res[--len] = '.';
		res[--len] = itg % 10 + '0';
		itg /= 10;
	}
}

void		print_do(t_ftp *p, long double flt)
{
	char			res[48];
	long long		itg;
	int				dot;
	int				prec;

	itg = (long long)flt;
	prec = p->preci;
	dot = p->preci == 0 && !(p->f & F_SHARP) ? 0 : 1;
	!(p->f & F_MINUS) && !(p->f & F_ZERO) ? padding(p, ' ') : 0;
	p->f & F_SPACE && flt >= 0 ? buffer(p, 1, " ") : 0;
	p->f & F_PLUS && flt >= 0 ? buffer(p, 1, "+") : 0;
	flt < 0 ? buffer(p, 1, "-") : 0;
	p->f & F_ZERO ? padding(p, '0') : 0;
	while (dot && (itg /= 10))
		dot++;
	while (prec--)
		flt *= 10;
	itg = flt > 0 ? (long long)flt : -(long long)flt;
	if ((long long)(flt * 10) % 10 > 4 || (long long)(flt * 10) % 10 < -4)
		itg += 1;
	putdouble(res, itg, dot, p);
	buffer(p, ft_strlen(res), res);
	p->f & F_MINUS ? padding(p, ' ') : 0;
}

intmax_t	ft_arg(t_ftp *p)
{
	intmax_t			n;

	n = 0;
	if (p->f & F_INTMAX || p->f & F_SIZET)
		n = va_arg(p->va, intmax_t);
	else if (p->f & F_LONG)
		n = (p->f & F_LONG2) ? va_arg(p->va, long long) :
			va_arg(p->va, long);
	else if (p->f & F_SHORT)
		n = (p->f & F_CHAR) ? (char)va_arg(p->va, int) :
			(short)va_arg(p->va, int);
	else
		n = (int)(va_arg(p->va, int));
	return (n);
}

uintmax_t	ft_uarg(t_ftp *p)
{
	uintmax_t			u;

	u = 0;
	if (p->f & F_INTMAX || p->f & F_SIZET)
		u = va_arg(p->va, uintmax_t);
	else if (p->f & F_LONG)
		u = (p->f & F_LONG2) ? va_arg(p->va, unsigned long long)
			: va_arg(p->va, unsigned long);
	else if (p->f & F_SHORT)
		u = (p->f & F_CHAR) ? (unsigned char)va_arg(p->va, unsigned int)
			: (unsigned short)va_arg(p->va, unsigned int);
	else
		u = va_arg(p->va, unsigned int);
	return (u);
}
