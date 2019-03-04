/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:43:19 by scoron            #+#    #+#             */
/*   Updated: 2019/03/04 21:45:56 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/types.h>

void				links(t_lsbox *lsbox, t_args *args)
{
		print_spaces(get_diff(lsbox, NULL, args->attr.links, LEN_LINKS));
		ft_printf("%d ", args->attr.links);
}

void				ino(t_lsbox *lsbox, t_args *args)
{
		if (!lsbox->opt.i)
				return ;
		print_spaces(get_diff(lsbox, NULL, args->attr.ino, LEN_INO));
		ft_printf("%lld ", args->attr.ino);
}

void				user_and_group(t_lsbox *lsbox, t_args *args)
{
		if (!(lsbox->opt.g))
		{
				ft_putstr(args->attr.user);
				print_spaces(get_diff(lsbox, args->attr.user, 0, LEN_USER) + 2);
		}
		if (!(lsbox->opt.o))
		{
				ft_putstr(args->attr.group);
				print_spaces(get_diff(lsbox, args->attr.group, 0, LEN_GROUP) + 2);
		}
		if (lsbox->opt.g && lsbox->opt.o)
				ft_printf("  ");
}

void				size(t_lsbox *lsbox, t_args *args)
{
	if (args->attr.chr)
	{
		print_spaces(get_diff(lsbox, NULL, 0, LEN_SIZE_C));
		ft_printf("%3d, %3d ", major(args->attr.rdev), minor(args->attr.rdev));
	}
	else
	{
		print_spaces(get_diff(lsbox, NULL, args->attr.size, LEN_SIZE));
		ft_printf("%d ", args->attr.size);
	}
}

void				display(t_lsbox *lsbox, t_args *args)
{
		t_attr			*attr;

		attr = &args->attr;
		ino(lsbox, args);
		if (lsbox->opt.l)
		{
				type(lsbox, args);
				links(lsbox, args);
				user_and_group(lsbox, args);
				size(lsbox, args);
				show_time(lsbox, args);
		}
		file_name(lsbox, args);
}
