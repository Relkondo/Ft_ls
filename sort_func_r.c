bool				sort_alpha_r(t_lsbox *lsbox)
{
	if (ft_strcmp(lsbox->track->attr.str, lsbox->track->next->attr.str) < 0)
		return (true);
	return (false);
}

bool				sort_size_r(t_lsbox *lsbox)
{
	if (lsbox->track->attr.size > lsbox->track->next->attr.size)
		return (true);
	return (false);
}

bool				sort_time_r(t_lsbox *lsbox)
{
	if (lsbox->option.c)
	{
		if (lsbox->track->attr.c_time > lsbox->track->next->attr.c_time)
			return (true);
		return (false);
	}
	if (lsbox->option.u)
	{
		if (lsbox->track->attr.u_time > lsbox->track->next->attr.u_time)
			return (true);
		return (false);
	}
	if (lsbox->option.U)
	{
		if (lsbox->track->attr.U_time > lsbox->track->next->attr.U_time)
			return (true);
		return (false);
	}
	else
	{
		if (lsbox->track->attr.t_time > lsbox->track->next->attr.t_time)
			return (true);
		return (false);
	}
}
