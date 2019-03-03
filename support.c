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

void				free_lsbox(t_lsbox *lsbox)
{
	(void)lsbox;
}

void				ls_error(t_lsbox *lsbox, char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	free_lsbox(lsbox);
	exit(1);
}
