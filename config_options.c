#include "ft_ls.h"

void				config_options(t_frame *frame)
{
	if (COLOUR)
		frame->option.G = 1;
	if (COLUMN)
		frame->option.x = 1;
	if (frame->option.d)
		frame->option.R = 0;
	if (frame->option.f)
		frame->option.a = 1;
	if (frame->option.S)
		frame->option.t = 0;
	if (frame->option.l)
		frame->option.x = 0;
	if (frame->option.one)
	{
		frame->option.l = 0;
		frame->option.x = 0;
	}
	assign_sort(frame);
}
