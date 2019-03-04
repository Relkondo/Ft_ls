#include "ft_ls.h"

void				config_opts(t_lsbox *lsbox)
{
	if (COLOUR)
		lsbox->opt.G = 1;
	if (COLUMN)
		lsbox->opt.x = 1;
	if (lsbox->opt.d)
		lsbox->opt.R = 0;
	if (lsbox->opt.f)
		lsbox->opt.a = 1;
	if (lsbox->opt.S)
		lsbox->opt.t = 0;
	if (lsbox->opt.l)
		lsbox->opt.x = 0;
	if (lsbox->opt.one)
	{
		lsbox->opt.l = 0;
		lsbox->opt.x = 0;
	}
	assign_sort(lsbox);
}
