#include "ft_ls.h"

t_lsbox		init_lsbox(int argc, char **argv)
{
		t_lsbox		lsbox;

		time(&lsbox.now);
		lsbox.6m_ago = lsbox.now - 6MONTHS;
		lsbox.argc = argc;
		lsbox.argv = argv;
		return (lsbox);
}

void		parsing(t_lsbox *lsbox)
{
		int			nb;

		lsbox->nb_opt = count_opt(lsbox);
		lsbox->argv_opt = ft_strndup(lsbox->argv, nb_opt);
		copy_args(lsbox, lsbox->argv + lsbox->nb_opt);
		handle_options(lsbox);
}

int			main(int argc, char **argv)
{
		t_lsbox		lsbox;

		lsbox = init_lsbox(argc, argv);
		parsing(&lsbox);
		return (0);
}
