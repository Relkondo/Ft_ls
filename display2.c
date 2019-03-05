/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:43:26 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 06:41:06 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_path(t_lsbox *lsbox, t_args *args, bool do_print)
{
	static intmax_t	print_path_count = 0;

	if (do_print)
	{
		if (lsbox->headers && print_path_count)
			ft_printf("\n%s:\n", args->attr.path);
		else if (lsbox->headers)
			ft_printf("%s:\n", args->attr.path);
	}
	print_path_count++;
}

void				print_spaces(int diff)
{
	char			*spaces;

	if (diff < 1)
		return ;
	if ((spaces = (char *)malloc(sizeof(char) * (diff + 1))))
	{
		ft_memset(spaces, ' ', diff);
		spaces[diff] = '\0';
		ft_putstr(spaces);
		free(spaces);
	}
}

int					get_diff(t_lsbox *lsbox, char *str, long long num, int flag)
{
	int				len;

	if ((len = 1) && str)
	{
		if (flag == LEN_USER)
			return (lsbox->len_user - ft_strlen(str));
		if (flag == LEN_GROUP)
			return (lsbox->len_group - ft_strlen(str));
		if (flag == LEN_NAME)
			return (lsbox->len_file_name - num);
	}
	if (flag == LEN_SIZE_C)
		return (lsbox->len_size - CHRSIZELEN);
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (flag == LEN_INO)
		return (lsbox->len_ino - len);
	if (flag == LEN_LINKS)
		return (lsbox->len_links - len);
	if (flag == LEN_SIZE)
		return (lsbox->len_size - len);
	return (0);
}

static time_t		get_file_time(t_lsbox *lsbox, t_args *args)
{
	if (lsbox->opt.c)
		return (args->attr.c_time);
	if (lsbox->opt.u)
		return (args->attr.u_time);
	if (lsbox->opt.U)
		return (args->attr.U_time);
	else
		return (args->attr.t_time);
}

void				show_time(t_lsbox *lsbox, t_args *args)
{
	char			*string;
	time_t			time;

	time = get_file_time(lsbox, args);
	string = ctime(&time);
	ft_printf("%3.3s ", string + 4);
	ft_printf("%2.2s ", string + 8);
	if (lsbox->opt.T)
		ft_printf("%.13s ", string + 11);
	else if (time < lsbox->six_months_ago || time > lsbox->now)
		ft_printf("%5.4s ", string + 20);
	else
		ft_printf("%5.5s ", string + 11);
	if (lsbox && args)
		;
}
