
#include "ft_ls.h"

bool				is_executeable(t_args_ch *args)
{
	int				type;

	type = args->attr.type;
	if ((type & 1) == 1 || (type >> 3 & 1) == 1 || (type >> 6 & 1) == 1)
		return (true);
	return (false);
}

void				calc_len_file_name(t_lsbox *lsbox, t_args_ch *args)
{
	int				len;
	t_attr			*attr;

	attr = &args->attr;
	len = ft_strlen(attr->str);
	attr->len_of_str = len;
	if (lsbox->option.up_f && (attr->dir || attr->lnk || attr->sock || attr->wht
				|| attr->ifo || is_executeable(args)))
		attr->len_of_str++;
	else if (lsbox->option.p && attr->dir)
		attr->len_of_str++;
	if (lsbox->option.up_f || lsbox->option.p)
		len++;
	if (len > lsbox->len_file_name)
		lsbox->len_file_name = len;
}

void				calc_len_group(t_lsbox *lsbox, t_args_ch *args)
{
	int				len;

	len = ft_strlen(args->attr.group);
	if (len > lsbox->len_group)
		lsbox->len_group = len;
}

void				calc_len_ino(t_lsbox *lsbox, t_args_ch *args)
{
	int				len;
	long long		num;

	len = 1;
	num = args->attr.ino;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > lsbox->len_ino)
		lsbox->len_ino = len;
}
