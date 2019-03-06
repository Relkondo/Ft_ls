/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_valid_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:53:45 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 07:47:18 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			reset_lengths(t_lsbox *lsbox)
{
	lsbox->len_ino = 0;
	lsbox->len_links = 0;
	lsbox->len_user = 0;
	lsbox->len_group = 0;
	lsbox->len_size = 0;
	lsbox->len_file_name = 0;
	lsbox->items_to_display = 0;
	lsbox->total_blocks = 0;
}

static void			register_lengths(t_lsbox *lsbox, t_args *args)
{
	t_args			*head;

	reset_lengths(lsbox);
	head = args;
	while (head)
	{
		if (!head->attr.no_file)
		{
			if (lsbox->opt.i)
				calc_len_ino(lsbox, head);
			calc_len_links(lsbox, head);
			calc_len_user(lsbox, head);
			calc_len_group(lsbox, head);
			calc_len_size(lsbox, head);
			calc_len_file_name(lsbox, head);
			lsbox->items_to_display++;
		}
		head = head->next;
	}
}

static void			do_loop(t_lsbox *lsbox, t_args *args, int *row_pos)
{
	while (args)
	{
		if (!args->attr.no_file)
		{
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
		args = args->next;
	}
}

void				loop_in_dir(t_lsbox *lsbox, t_args *head)
{
	t_args			*args;
	int				row_pos;

	row_pos = 0;
	if (lsbox->opt.d)
		return ;
	args = head;
	if (lsbox->opt.l)
		ft_printf("total %d\n", lsbox->total_blocks);
	register_lengths(lsbox, head);
	calc_nb_col(lsbox);
	do_loop(lsbox, args, &row_pos);
	if (row_pos && lsbox->opt.x)
		ft_putchar('\n');
	if (lsbox->opt.N)
		ft_printf(NUM_FILES, lsbox->items_to_display);
}
