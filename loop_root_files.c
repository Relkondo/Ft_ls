/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_root_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:44:18 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 14:35:07 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			register_lengths(t_lsbox *lsbox, t_args *args)
{
	t_args			*tmp;

	lsbox->len_ino = 0;
	lsbox->len_links = 0;
	lsbox->len_user = 0;
	lsbox->len_group = 0;
	lsbox->len_size = 0;
	lsbox->len_file_name = 0;
	lsbox->items_to_display = 0;
	tmp = args;
	while (tmp)
	{
		if ((!tmp->attr.dir || lsbox->opt.d) && !tmp->attr.no_file)
		{
			if (lsbox->opt.i)
				calc_len_ino(lsbox, tmp);
			calc_len_links(lsbox, tmp);
			calc_len_user(lsbox, tmp);
			calc_len_group(lsbox, tmp);
			calc_len_size(lsbox, tmp);
			calc_len_file_name(lsbox, tmp);
			lsbox->items_to_display++;
		}
		tmp = tmp->next;
	}
}

static void			display_file(t_lsbox *lsbox, t_args *args,
		int *row_pos)
{
	print_path(lsbox, args, false);
	display(lsbox, args);
	*row_pos += 1;
	if (*row_pos >= lsbox->nb_columns)
	{
		ft_putchar('\n');
		*row_pos = 0;
	}
	else if (!lsbox->opt.x)
		ft_putchar('\n');
}

void				loop_root_files(t_lsbox *lsbox)
{
	t_args			*args;
	int				row_pos;

	row_pos = 0;
	args = lsbox->args;
	register_lengths(lsbox, args);
	calc_nb_col(lsbox);
	while (args)
	{
		if ((!args->attr.dir || lsbox->opt.d) && !args->attr.no_file)
			display_file(lsbox, args, &row_pos);
		args = args->next;
	}
	if (row_pos && lsbox->opt.x)
		ft_putchar('\n');
	if (lsbox->opt.cap_n && lsbox->items_to_display)
		ft_printf(NUM_FILES, lsbox->items_to_display);
}
