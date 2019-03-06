/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 01:17:39 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 13:54:29 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_args	*add_args_element(void)
{
	t_args			*args;

	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (NULL);
	ft_bzero(args, sizeof(*args));
	return (args);
}

void	register_args(t_lsbox *lsbox, char **argv)
{
	t_args			*args;
	t_args			*last_args;

	if (!*argv)
	{
		if (!(lsbox->args = add_args_element()))
			ls_error(lsbox, "Malloc Failed");
		if (!(lsbox->args->attr.str = ft_strdup("."))
				|| !(lsbox->args->attr.path = ft_strdup(".")))
			ls_error(lsbox, "Malloc Failed");
	}
	while (*argv)
	{
		if (!(args = add_args_element()))
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
