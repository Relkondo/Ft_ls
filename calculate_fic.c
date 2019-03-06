/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:43:08 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 14:05:37 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				is_executeable(t_args *args)
{
	int				type;

	type = args->attr.type;
	if ((type & 1) == 1 || (type >> 3 & 1) == 1 || (type >> 6 & 1) == 1)
		return (true);
	return (false);
}

void				calc_len_file_name(t_lsbox *lsbox, t_args *args)
{
	int				len;
	t_attr			*attr;

	attr = &args->attr;
	len = ft_strlen(attr->str);
	attr->len_of_str = len;
	if (lsbox->opt.cap_f && (attr->dir || attr->lnk || attr->sock || attr->wht
				|| attr->ifo || is_executeable(args)))
		attr->len_of_str++;
	else if (lsbox->opt.p && attr->dir)
		attr->len_of_str++;
	if (lsbox->opt.cap_f || lsbox->opt.p)
		len++;
	if (len > lsbox->len_file_name)
		lsbox->len_file_name = len;
}

void				calc_len_ino(t_lsbox *lsbox, t_args *args)
{
	int				len;
	long long		num;

	len = 1;
	num = args->attr.ino;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > lsbox->len_ino)
		lsbox->len_ino = len;
}

void				calc_nb_col(t_lsbox *lsbox)
{
	int				column_width;

	column_width = lsbox->len_file_name + 1;
	if (lsbox->opt.i)
		column_width += lsbox->len_ino + 1;
	lsbox->nb_columns = lsbox->width / column_width;
}
