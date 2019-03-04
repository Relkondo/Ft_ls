
#include "ft_ls.h"

void				loop_no_file(t_lsbox *lsbox)
{
	t_args_ch			*args;

	args = lsbox->args;
	while (args)
	{
		if (args->attr.no_file)
			no_file(lsbox, args);
		args = args->next;
	}
}

void				loop_dirs(t_lsbox *lsbox)
{
	t_args_ch			*args;

	if (lsbox->option.d)
		return ;
	args = lsbox->args;
	while (args)
	{
		if (args->attr.dir && !args->attr.no_file)
			ls_loop(lsbox, args);
		args = args->next;
	}
}

void			loop_init(t_lsbox *lsbox)
{
	loop_no_file(lsbox);
	loop_files(lsbox);
	loop_dirs(lsbox);
}
