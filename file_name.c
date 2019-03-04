/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:43:34 by scoron            #+#    #+#             */
/*   Updated: 2019/03/04 22:43:08 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_end_char(t_lsbox *lsbox, t_args *args)
{
	if (lsbox->opt.F)
	{
		if (args->attr.ifo)
			ft_putchar('|');
		else if (args->attr.dir)
			ft_putchar('/');
		else if (args->attr.lnk)
			ft_putchar('@');
		else if (args->attr.sock)
			ft_putchar('=');
		else if (args->attr.wht)
			ft_putchar('%');
		else if (is_executeable(args))
			ft_putchar('*');
	}
	else if (lsbox->opt.p && args->attr.dir)
		ft_putchar('/');
}

static void			print_colour(t_args *args)
{
	if (is_executeable(args))
		ft_putstr(COL_EXE);
	if (args->attr.ifo)
		ft_putstr(COL_IFO);
	if (args->attr.chr)
		ft_putstr(COL_CHR);
	if (args->attr.dir)
		ft_putstr(COL_DIR);
	if (args->attr.blk)
		ft_putstr(COL_BLK);
	if (args->attr.reg && !is_executeable(args))
		ft_putstr(COL_REG);
	if (args->attr.lnk)
		ft_putstr(COL_LNK);
	if (args->attr.sock)
		ft_putstr(COL_SOCK);
	ft_printf("%s", args->attr.str);
	ft_putstr(COL_CLR);
}

void				file_name(t_lsbox *lsbox, t_args *args)
{
	t_attr			*attr;
	int				len;

	attr = &args->attr;
	len = attr->len_of_str;
	if (lsbox->opt.G)
		print_colour(args);
	else
		ft_printf("%s", attr->str);
	print_end_char(lsbox, args);
	if (lsbox->opt.l && attr->lnk)
		ft_printf(" -> %s", attr->sym_path);
	if (lsbox->number_of_columns && !lsbox->opt.l)
		print_spaces(get_diff(lsbox, attr->str, len, LEN_NAME) + 1);
}
