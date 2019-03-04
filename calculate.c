/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:43:02 by scoron            #+#    #+#             */
/*   Updated: 2019/03/04 22:39:11 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				calc_len_links(t_lsbox *lsbox, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->attr.links;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > lsbox->len_links)
		lsbox->len_links = len;
}

void				calc_len_size(t_lsbox *lsbox, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->attr.size;
	if (args->attr.chr)
		len = CHRSIZELEN;
	else
		while (num >= 10)
		{
			num /= 10;
			len++;
		}
	if (len > lsbox->len_size)
		lsbox->len_size = len;
}

void				calc_len_user(t_lsbox *lsbox, t_args *args)
{
	int				len;

	len = ft_strlen(args->attr.user);
	if (len > lsbox->len_user)
		lsbox->len_user = len;
}

void				calculate_number_of_columns(t_lsbox *lsbox)
{
	int				column_width;

	column_width = lsbox->len_file_name + 1;
	if (lsbox->opt.i)
		column_width += lsbox->len_ino + 1;
	lsbox->number_of_columns = lsbox->width / column_width;
}
