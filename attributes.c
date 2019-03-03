/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:42:04 by scoron            #+#    #+#             */
/*   Updated: 2019/03/03 12:50:34 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




void				attributes(t_lsbox *lsbox)
{
	t_arg_ch			*arg_ch;
	struct stat			func;

	arg_ch = lsbox->current_arg_ch;
	while (arg_ch)
	{
		if (!lstat(arg_ch->data.path, &func))
			read_f(lsbox, arg_ch, &func);
		else
			arg_ch->data.n_file = 1;
		arg_ch = arg_ch->next;
	}
}
