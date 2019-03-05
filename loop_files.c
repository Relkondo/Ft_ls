/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:44:18 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 07:41:10 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			get_column_widths(t_lsbox *lsbox, t_args *args)
{
	t_args			*head;

	lsbox->len_ino = 0;
	lsbox->len_links = 0;
	lsbox->len_user = 0;
	lsbox->len_group = 0;
	lsbox->len_size = 0;
	lsbox->len_file_name = 0;
	lsbox->items_to_display = 0;
	head = args;
	while (head)
	{
		if ((!head->attr.dir || lsbox->opt.d) && !head->attr.no_file)
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

static void			display_file(t_lsbox *lsbox, t_args *args,
		int *position_on_row)
{
	print_path(lsbox, args, false);
	display(lsbox, args);
	*position_on_row += 1;
	if (*position_on_row >= lsbox->number_of_columns)
	{
		ft_putchar('\n');
		*position_on_row = 0;
	}
	else if (!lsbox->opt.x)
		ft_putchar('\n');
}

void				loop_files(t_lsbox *lsbox)
{
	t_args			*args;
	int				position_on_row;

	position_on_row = 0;
	args = lsbox->args;
	get_column_widths(lsbox, args);
	calculate_number_of_columns(lsbox);
	while (args)
	{
		if ((!args->attr.dir || lsbox->opt.d) && !args->attr.no_file)
			display_file(lsbox, args, &position_on_row);
		args = args->next;
	}
	if (position_on_row && lsbox->opt.x)
		ft_putchar('\n');
	if (lsbox->opt.N && lsbox->items_to_display)
		ft_printf(NUM_FILES, lsbox->items_to_display);
}
