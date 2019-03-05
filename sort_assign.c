/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:44:52 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 03:31:20 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			sort_reverse(t_lsbox *lsbox)
{
	if (lsbox->opt.S)
		lsbox->sort_func = &sort_size_r;
	else if (lsbox->opt.t)
		lsbox->sort_func = &sort_time_r;
	else
		lsbox->sort_func = NULL;
}

static void			sort_normal(t_lsbox *lsbox)
{
	if (lsbox->opt.S)
		lsbox->sort_func = &sort_size;
	else if (lsbox->opt.t)
		lsbox->sort_func = &sort_time;
	else
		lsbox->sort_func = NULL;
}

void				assign_sort(t_lsbox *lsbox)
{
	if (!lsbox->opt.r)
		sort_normal(lsbox);
	else
		sort_reverse(lsbox);
}
