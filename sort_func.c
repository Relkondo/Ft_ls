/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:44:58 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 13:03:57 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				sort_alpha(t_lsbox *lsbox)
{
	if (!lsbox->opt.r)
	{
		if (ft_strcmp(lsbox->track->attr.str, lsbox->track->next->attr.str) > 0)
			return (true);
		return (false);
	}
	else
	{
		if (ft_strcmp(lsbox->track->attr.str, lsbox->track->next->attr.str) < 0)
			return (true);
		return (false);
	}
}

bool				sort_size(t_lsbox *lsbox)
{
	if (!lsbox->opt.r)
	{
		if (lsbox->track->attr.size < lsbox->track->next->attr.size)
			return (true);
		return (false);
	}
	else
	{
		if (lsbox->track->attr.size > lsbox->track->next->attr.size)
			return (true);
		return (false);
	}
}

bool				sort_time(t_lsbox *lsbox)
{
	if (lsbox->opt.c)
	{
		if (lsbox->track->attr.c_time < lsbox->track->next->attr.c_time)
			return (true);
		return (false);
	}
	if (lsbox->opt.u)
	{
		if (lsbox->track->attr.u_time < lsbox->track->next->attr.u_time)
			return (true);
		return (false);
	}
	if (lsbox->opt.U)
	{
		if (lsbox->track->attr.U_time < lsbox->track->next->attr.U_time)
			return (true);
		return (false);
	}
	else
	{
		if (lsbox->track->attr.t_time < lsbox->track->next->attr.t_time)
			return (true);
		return (false);
	}
}

bool				sort_time_r(t_lsbox *lsbox)
{
	if (lsbox->opt.c)
	{
		if (lsbox->track->attr.c_time > lsbox->track->next->attr.c_time)
			return (true);
		return (false);
	}
	if (lsbox->opt.u)
	{
		if (lsbox->track->attr.u_time > lsbox->track->next->attr.u_time)
			return (true);
		return (false);
	}
	if (lsbox->opt.U)
	{
		if (lsbox->track->attr.U_time > lsbox->track->next->attr.U_time)
			return (true);
		return (false);
	}
	else
	{
		if (lsbox->track->attr.t_time > lsbox->track->next->attr.t_time)
			return (true);
		return (false);
	}
}
