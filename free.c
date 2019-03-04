#include "ft_ls.h"

static void		free_each_args(t_lsbox *lsbox, t_args_ch *args)
{
		free(args->attr.str);
		free(args->attr.path);
		free(args->attr.user);
		free(args->attr.group);
}

void			free(t_lsbox *lsbox, t_args_ch **head)
{
	t_args_ch		*args;
	t_args_ch		*tmp;

	args = *head;
	while (args)
	{
		tmp = args;
		free_each_args(lsbox, args);
		args = args->next;
		free(tmp);
	}
	*head = NULL;
	free(lsbox->argv_opts);
}
