/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:40:13 by scoron            #+#    #+#             */
/*   Updated: 2019/03/03 12:40:15 by scoron           ###   ########.fr       */
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
	free_lsbox(lsbox);
	exit(1);
}

t_args_ch				*create_args(void)
{
	t_args_ch			*args;

	if (!(args = (t_args *)malloc(sizeof(t_args_ch))))
		return (NULL);
	ft_bzero(args, sizeof(*args));
	return (args);
}

void				path(t_lsbox *lsbox, t_args_ch *args, char *path, char *name)
{
	char			*new_path;
	char			*tmp;

	if (!(args->attr.str = ft_strdup(name)))
		args->attr.str = lsbox->malloc_failed;
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		args->attr.path = lsbox->malloc_failed;
	else
	{
		tmp = new_path;
		if (ft_strcmp(path, "."))
		{
			while (path && *path)
				*(tmp++) = *(path++);
			*(tmp++) = '/';
		}
		while (name && *name)
			*(tmp++) = *(name++);
		args->attr.path = new_path;
	}
}
