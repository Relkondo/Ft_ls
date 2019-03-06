/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_effect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:44:52 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 14:48:16 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				assign_sort(t_lsbox *lsbox)
{
	if (lsbox->opt.cap_s)
		lsbox->sort_func = &sort_size;
	else if (lsbox->opt.t && !lsbox->opt.r)
		lsbox->sort_func = &sort_time;
	else if (lsbox->opt.t && lsbox->opt.r)
		lsbox->sort_func = &sort_time_r;
	else
		lsbox->sort_func = NULL;
}

void				opt_effect(t_lsbox *lsbox)
{
	if (COLOUR)
		lsbox->opt.cap_g = 1;
	if (COLUMN)
		lsbox->opt.x = 1;
	if (lsbox->opt.cap_s)
		lsbox->opt.t = 0;
	if (lsbox->opt.l)
		lsbox->opt.x = 0;
	if (lsbox->opt.d)
		lsbox->opt.cap_r = 0;
	if (lsbox->opt.f)
		lsbox->opt.a = 1;
	if (lsbox->opt.one)
		lsbox->opt.x = 0;
	assign_sort(lsbox);
}
