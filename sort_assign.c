#include "ft_ls.h"

static void			sort_reverse(t_lsbox *lsbox)
{
	if (lsbox->option.up_s)
		lsbox->sort_func = &sort_size_r;
	else if (lsbox->option.t)
		lsbox->sort_func = &sort_time_r;
	else
		lsbox->sort_func = NULL;
}

static void			sort_normal(t_lsbox *lsbox)
{
	if (lsbox->option.up_s)
		lsbox->sort_func = &sort_size;
	else if (lsbox->option.t)
		lsbox->sort_func = &sort_time;
	else
		lsbox->sort_func = NULL;
}

void				assign_sort(t_lsbox *lsbox)
{
	if (!lsbox->option.r)
		sort_normal(lsbox);
	else
		sort_reverse(lsbox);
}
