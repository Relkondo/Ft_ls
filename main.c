#include "ft_ls.h"
#include <stdio.h>

t_lsbox		init_lsbox(int argc, char **argv)
{
		t_lsbox		lsbox;

		time(&lsbox.now);
		lsbox.six_months_ago = lsbox.now - SIX_MONTHS;
		lsbox.argc = argc - 1;
		lsbox.argv = argv + 1;
		return (lsbox);
}

void		parsing(t_lsbox *lsbox)
{
		lsbox->nb_opt = count_opt(lsbox);
		lsbox->argv_opt = ft_strndup_p(lsbox->argv, lsbox->nb_opt);
		lsbox->argv = ft_strndup_p(lsbox->argv + lsbox->nb_opt, lsbox->argc - lsbox->nb_opt);
		register_options(lsbox);
}

int			main(int argc, char **argv)
{
		t_lsbox		lsbox;

		lsbox = init_lsbox(argc, argv);
		parsing(&lsbox);
		attributes(lsbox);
		return (0);
}
