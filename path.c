/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 05:42:21 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 09:11:01 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		path_copy(char *new_path, char *path, char *name)
{
	char			*tmp;

	tmp = new_path;
	if (ft_strcmp(path, "."))
	{
		while (path && *path)
			*(tmp++) = *(path++);
		*(tmp++) = '/';
	}
	while (name && *name)
		*(tmp++) = *(name++);
}

void		path(t_lsbox *lsbox, t_args *args, char *path, char *name)
{
	char			*new_path;

	if (!(args->attr.str = ft_strdup(name)))
		ls_error(lsbox, "malloc attr.str failed");
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		ls_error(lsbox, "malloc new_path failed");
	else
	{
		path_copy(new_path, path, name);
		args->attr.path = new_path;
	}
}

void		path_r(t_lsbox *lsbox, t_args *args, char *path, char *name)
{
	char			*new_path;

	if (!(args->attr.str = ft_strdup(name)))
		ls_error(lsbox, "malloc attr.str failed");
	if (lsbox->opt.R && (path[0] != '.' || path[1] != '/'))
	{
		if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 3)))
			ls_error(lsbox, "malloc new_path failed");
		else
		{
			new_path[0] = '.';
			new_path[1] = '/';
			path_copy(new_path + 2, path, name);
			args->attr.path = new_path;
		}
	}
	else
	{
		if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
			ls_error(lsbox, "malloc new_path failed");
		else
		{
			path_copy(new_path, path, name);
			args->attr.path = new_path;
		}
	}
}
