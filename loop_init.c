/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:44:28 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 07:41:21 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void	loop_no_file(t_lsbox *lsbox)
{
	t_args			*args;

	args = lsbox->args;
	while (args)
	{
		if (args->attr.no_file)
			no_file(lsbox, args);
		args = args->next;
	}
}

void	loop_dirs(t_lsbox *lsbox)
{
	t_args			*args;

	if (lsbox->opt.d)
		return ;
	args = lsbox->args;
	while (args)
	{
		if (args->attr.dir && !args->attr.no_file)
			ls_loop(lsbox, args);
		args = args->next;
	}
}

void	loop_init(t_lsbox *lsbox)
{
	loop_no_file(lsbox);
	loop_files(lsbox);
	loop_dirs(lsbox);
}
