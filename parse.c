/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 01:17:39 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 04:59:37 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			parse_args(t_lsbox *lsbox, char **argv)
{
	t_args			*args;
	t_args			*last_args;

	if (!*argv)
	{
		if (!(lsbox->args = create_args()))
			ls_error(lsbox, "Malloc Failed");
		if (!(lsbox->args->attr.str = ft_strdup("."))
				|| !(lsbox->args->attr.path = ft_strdup(".")))
			ls_error(lsbox, "Malloc Failed");
	}
	while (*argv)
	{
		if (!(args = create_args()))
			ls_error(lsbox, "Malloc Failed");
		path(lsbox, args, ".", *argv);
		if (!lsbox->args)
			lsbox->args = args;
		else
			last_args->next = args;
		last_args = args;
		argv++;
	}
}
