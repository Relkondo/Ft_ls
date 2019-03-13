/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 05:42:21 by scoron            #+#    #+#             */
/*   Updated: 2019/03/13 20:54:47 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		path_copy(t_lsbox *lsbox, char *new_path, char *path, char *name)
{
	char			*tmp;
	char			*path_init;

	tmp = new_path;
	path_init = path;
	//usleep(200000);
	if (ft_strcmp(name, "/") && (ft_strcmp(path, ".") || lsbox->opt.cap_r))
	{
		//ft_printf("1name : %s, path : %s\n", name, path);
		while (path && *path)
			*(tmp++) = *(path++);
		if (ft_strcmp(path_init, "/"))
			*(tmp++) = '/';
	}
	//ft_printf("2name : %s, path : %s, new_path : %s\n", name, path, new_path);
	while (name && *name)
		*(tmp++) = *(name++);
	//ft_printf("3name : %s, path : %s, new_path : %s\n", name, path, new_path);
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
		path_copy(lsbox, new_path, path, name);
		args->attr.path = new_path;
	}
}
