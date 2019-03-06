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
