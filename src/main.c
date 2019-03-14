/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:39:50 by scoron            #+#    #+#             */
/*   Updated: 2019/03/14 12:33:29 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

static t_lsbox	init_lsbox(int argc, char **argv)
{
	t_lsbox			lsbox;
	struct winsize	wsize;

	time(&lsbox.now);
	lsbox.six_months_ago = lsbox.now - SIX_MONTHS;
	lsbox.argc = argc - 1;
	lsbox.argv = argv + 1;
	lsbox.headers = 0;
	lsbox.nb_columns = 0;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize) == -1)
		lsbox.opt.one = 1;
	lsbox.width = wsize.ws_col;
	return (lsbox);
}

static void		parsing(t_lsbox *lsbox)
{
	lsbox->nb_opt = count_opt(lsbox);
	lsbox->argv_opt = ft_strndup_p(lsbox->argv, lsbox->nb_opt);
	if (!(lsbox->argv_opt))
		ls_error(lsbox, "Malloc Argv_opt Failed");
	register_args(lsbox, lsbox->argv + lsbox->nb_opt);
	register_opts(lsbox);
	opt_effect(lsbox);
	lsbox->current_args = lsbox->args;
	register_attr(lsbox);
}

static void		init_headers(t_lsbox *lsbox)
{
	t_args			*args;
	int				headers;
	int				not_dir;

	if (lsbox->opt.d)
		return ;
	args = lsbox->args;
	headers = 0;
	not_dir = 0;
	while (args && !lsbox->headers)
	{
		if (!not_dir && !args->attr.dir)
			not_dir++;
		if (args->attr.dir)
			headers++;
		if (headers > 1 || (headers && not_dir))
			lsbox->headers = 1;
		args = args->next;
	}
}

int				main(int argc, char **argv)
{
	t_lsbox		lsbox;

	lsbox = init_lsbox(argc, argv);
	parsing(&lsbox);
	sort(&lsbox);
	lsbox.args = lsbox.current_args;
	init_headers(&lsbox);
	loop_init(&lsbox);
	free_ls(&lsbox);
	return (0);
}
