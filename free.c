/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:43:40 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 07:30:21 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		free_each_args(t_args *args)
{
		free(args->attr.str);
		free(args->attr.path);
		free(args->attr.user);
		free(args->attr.group);
}

void			free_args(t_lsbox *lsbox, t_args **head)
{
	t_args		*args;
	t_args		*tmp;

	(void)lsbox;
	args = *head;
	while (args)
	{
		tmp = args;
		free_each_args(args);
		args = args->next;
		free(tmp);
	}
	*head = NULL;
}

void				free_ls(t_lsbox *lsbox)
{
		free_args(lsbox, &lsbox->args);
		free(lsbox->argv_opt);
}

void				ls_error(t_lsbox *lsbox, char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	free_ls(lsbox);
	exit(1);
}
