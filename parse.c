#include "ft_ls.h"

int			count_opt(t_lsbox lsbox)
{
		int				nb_opt;
		char			**argv;

		argv = lsbox->argv + 1;
		np_opt = 0;
		while (*argv && **argv == '-' && *(*argv + 1))
		{
				np_opt++;
				ft_strcmp(*argv, "--") ? 0 : break;
				argv++;
		}
		return (np_opt);
}
