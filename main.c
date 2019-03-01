#include "ft_ls.h"

t_lsbox		init_lsbox(int argc, char **argv)
{
		t_lsbox		lsbox;

		time(&lsbox.now);
		lsbox.6m_ago = lsbox.now - 6MONTHS;
		lsbox.argc = argc;
		lsbox.argv = argv;
		if (!(lsbox.nomalloc = ft_strdup("COULD NOT MALLOC")))
				exit(1);
		return (lsbox);
}

int			main(int argc, char **argv)
{
		t_lsbox		lsbox;

		lsbox = init_lsbox(argc, argv);
		parse(lsbox);
		return (0);
}
