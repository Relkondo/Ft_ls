/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:40:13 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 09:42:49 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				config_opts(t_lsbox *lsbox)
{
	if (COLOUR)
		lsbox->opt.G = 1;
	if (COLUMN)
		lsbox->opt.x = 1;
	if (lsbox->opt.d)
		lsbox->opt.R = 0;
	if (lsbox->opt.f)
		lsbox->opt.a = 1;
	if (lsbox->opt.S)
		lsbox->opt.t = 0;
	if (lsbox->opt.l)
		lsbox->opt.x = 0;
	if (lsbox->opt.one)
	{
		lsbox->opt.l = 0;
		lsbox->opt.x = 0;
	}
	assign_sort(lsbox);
}

void				ls_error(t_lsbox *lsbox, char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	free_ls(lsbox);
	exit(1);
}

void				no_file(t_lsbox *lsbox, t_args *args)
{
	if (args->attr.no_file && lsbox)
		ft_printf("ft_ls: %s: No such file or directory\n", args->attr.str);
	args = args->next;
}

t_args				*create_args(void)
{
	t_args			*args;

	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (NULL);
	ft_bzero(args, sizeof(*args));
	return (args);
}
