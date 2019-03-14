/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:20:06 by scoron            #+#    #+#             */
/*   Updated: 2019/02/11 17:45:08 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_ftp		p;

	p.format = format;
	p.retv = 0;
	p.len_buf = 0;
	p.buf = ft_strnew(BUF_SIZE);
	va_start(p.va, format);
	while (*(p.format))
	{
		if (*(p.format) == '%' && p.format++)
			parse_options(&p);
		else
			buffer(&p, 1, p.format);
		(p.format)++;
	}
	va_end(p.va);
	buffer(&p, -1, 0);
	free(p.buf);
	return (p.retv);
}

void	buffer(t_ftp *p, int n, char *str)
{
	while (n > 0 && BUF_SIZE - p->len_buf >= n)
	{
		p->buf[p->len_buf] = *str;
		p->padding ? 0 : str++;
		p->len_buf++;
		p->retv++;
		n--;
	}
	p->padding = 0;
	if (p->len_buf == BUF_SIZE || n == -1 || n > BUF_SIZE - p->len_buf)
	{
		write(1, p->buf, p->len_buf);
		p->len_buf = 0;
	}
	if (n > BUF_SIZE)
		write(1, str, n);
	else if (n > 0)
		buffer(p, n, str);
}

void	padding(t_ftp *p, char c)
{
	char	str[1];

	str[0] = c;
	p->padding = p->min - p->size;
	buffer(p, p->padding, str);
}
