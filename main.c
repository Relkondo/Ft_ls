/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:39:50 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 09:42:40 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

t_lsbox		init_lsbox(int argc, char **argv)
{
		t_lsbox		lsbox;
		struct winsize	wsize;

		time(&lsbox.now);
		lsbox.six_months_ago = lsbox.now - SIX_MONTHS;
		lsbox.argc = argc - 1;
		lsbox.argv = argv + 1;
		lsbox.headers = 0;
		lsbox.number_of_columns = 0;
		if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize) == -1)
		lsbox.opt.one = 1;
		lsbox.width = wsize.ws_col;
		return (lsbox);
}

void		parsing(t_lsbox *lsbox)
{
		lsbox->nb_opt = count_opt(lsbox);
		lsbox->argv_opt = ft_strndup_p(lsbox->argv, lsbox->nb_opt);
		if (!(lsbox->argv_opt))
			ls_error(lsbox, "Malloc Argv_opt Failed");
		parse_args(lsbox, lsbox->argv + lsbox->nb_opt);
		register_opts(lsbox);
		config_opts(lsbox);
}

static void	check_headers(t_lsbox *lsbox)
{
		t_args			*args;
		int				headers;
		int				not_dir;

		args = lsbox->args;
		headers = 0;
		not_dir = 0;
		while (args && !lsbox->headers)
		{
				if (!not_dir && !args->attr.dir && !lsbox->opt.d)
						not_dir++;
				if (args->attr.dir && !lsbox->opt.d)
						headers++;
				if (headers > 1 || (headers && not_dir))
						lsbox->headers = 1;
				args = args->next;
		}
}

int			main(int argc, char **argv)
{
		t_lsbox		lsbox;

		lsbox = init_lsbox(argc, argv);
		parsing(&lsbox);
		lsbox.current_args = lsbox.args;
		attributes(&lsbox);
		sort(&lsbox);
		lsbox.args = lsbox.current_args;
		check_headers(&lsbox);
		loop_init(&lsbox);
		free_ls(&lsbox);
		return (0);
}
