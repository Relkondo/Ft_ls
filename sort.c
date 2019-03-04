#include "ft_ls.h"

static int			swap(t_lsbox *lsbox)
{
	t_attr			tmp;

	if (lsbox->sort_func(lsbox))
	{
		tmp = lsbox->track->attr;
		lsbox->track->attr = lsbox->track->next->attr;
		lsbox->track->next->attr = tmp;
		return (1);
	}
	return (0);
}

static void			do_sort(t_lsbox *lsbox)
{
	int				sorted;

	while (1)
	{
		lsbox->track = lsbox->head;
		sorted = 1;
		while (lsbox->track && lsbox->track->next)
		{
			if (swap(lsbox))
				sorted = 0;
			lsbox->track = lsbox->track->next;
		}
		if (sorted)
			break ;
	}
}

void				sort(t_lsbox *lsbox)
{
	bool			(*tmp)(struct s_lsbox *lsbox);

	if (lsbox->option.func)
		return ;
	tmp = lsbox->sort_func;
	if (!lsbox->option.r)
		lsbox->sort_func = &sort_alpha;
	else
		lsbox->sort_func = &sort_alpha_r;
	lsbox->head = lsbox->current_args;
	do_sort(lsbox);
	lsbox->sort_func = tmp;
	if (tmp)
		do_sort(lsbox);
	lsbox->current_args = lsbox->head;
}
