/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:44:11 by scoron            #+#    #+#             */
/*   Updated: 2019/03/13 19:33:33 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

static bool			register_dir(t_read_dir *read_dir)
{
	if ((read_dir->lsbox->opt.cap_a && (ft_strcmp(read_dir->file->d_name, ".")
					&& ft_strcmp(read_dir->file->d_name, "..")))
			|| read_dir->lsbox->opt.a || (read_dir->file->d_name[0] != '.'))
	{
		if (!(read_dir->tmp = add_args_element()))
		{
			free_args(read_dir->lsbox, &read_dir->head);
			return (false);
		}
		path(read_dir->lsbox, read_dir->tmp, read_dir->args->attr.path,
				read_dir->file->d_name);
		if (!read_dir->head)
			read_dir->head = read_dir->tmp;
		else
			read_dir->last_args->next = read_dir->tmp;
		read_dir->last_args = read_dir->tmp;
	}
	return (true);
}

static t_args		*get_dir_contents(t_lsbox *lsbox, t_args *args)
{
	t_read_dir		read_dir;

	read_dir.lsbox = lsbox;
	read_dir.args = args;
	read_dir.head = NULL;
	if (!(read_dir.directory = opendir(read_dir.args->attr.path)))
	{
		ft_printf("ls: %s: Permission denied\n", read_dir.args->attr.str);
		return (NULL);
	}
	while ((read_dir.file = readdir(read_dir.directory)))
	{
		if (!register_dir(&read_dir))
			return (NULL);
	}
	closedir(read_dir.directory);
	return (read_dir.head);
}

static void			check_headers(t_lsbox *lsbox, t_args *head)
{
	t_args			*args;

	args = head;
	while (args && !lsbox->headers)
	{
		if (lsbox->opt.cap_r && args->attr.dir && !lsbox->opt.d)
			lsbox->headers = 1;
		args = args->next;
	}
}

void				ls_loop(t_lsbox *lsbox, t_args *args)
{
	t_args			*head;
	t_args			*tmp;

	print_path(lsbox, args, true);
	check_headers(lsbox, args);
	if (!(head = get_dir_contents(lsbox, args)))
		return ;
	lsbox->current_args = head;
	register_attr(lsbox);
	sort(lsbox);
	head = lsbox->current_args;
	loop_in_dir(lsbox, head);
	if (lsbox->opt.cap_r)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->attr.dir && ft_strcmp(tmp->attr.str, ".")
					&& ft_strcmp(tmp->attr.str, ".."))
				ls_loop(lsbox, tmp);
			tmp = tmp->next;
		}
	}
	free_args(lsbox, &head);
}
