/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:43:19 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 14:04:20 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>

void	d_links(t_lsbox *lsbox, t_args *args)
{
	d_space(get_diff(lsbox, NULL, args->attr.links, LEN_LINKS));
	ft_printf("%d ", args->attr.links);
}

void	d_ino(t_lsbox *lsbox, t_args *args)
{
	if (!lsbox->opt.i)
		return ;
	d_space(get_diff(lsbox, NULL, args->attr.ino, LEN_INO));
	ft_printf("%lld ", args->attr.ino);
}

void	d_user_and_group(t_lsbox *lsbox, t_args *args)
{
	if (!(lsbox->opt.g))
	{
		ft_putstr(args->attr.user);
		d_space(get_diff(lsbox, args->attr.user, 0, LEN_USER) + 2);
	}
	if (!(lsbox->opt.o))
	{
		ft_putstr(args->attr.group);
		d_space(get_diff(lsbox, args->attr.group, 0, LEN_GROUP) + 2);
	}
	if (lsbox->opt.g && lsbox->opt.o)
		ft_printf("  ");
}

void	d_size(t_lsbox *lsbox, t_args *args)
{
	if (args->attr.chr)
	{
		d_space(get_diff(lsbox, NULL, 0, LEN_SIZE_C));
		ft_printf("%3d, %3d ", major(args->attr.rdev), minor(args->attr.rdev));
	}
	else
	{
		d_space(get_diff(lsbox, NULL, args->attr.size, LEN_SIZE));
		ft_printf("%d ", args->attr.size);
	}
}

void	display(t_lsbox *lsbox, t_args *args)
{
	t_attr			*attr;

	attr = &args->attr;
	d_ino(lsbox, args);
	if (lsbox->opt.l)
	{
		d_type(lsbox, args);
		d_links(lsbox, args);
		d_user_and_group(lsbox, args);
		d_size(lsbox, args);
		d_time(lsbox, args);
	}
	d_file_name(lsbox, args);
}
