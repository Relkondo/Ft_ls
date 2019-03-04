/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:42:04 by scoron            #+#    #+#             */
/*   Updated: 2019/03/03 12:50:34 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>

static void			get_sym_path(t_args *args_ch)
{
	int				len;
	t_data			*data;

	data = &args_ch->data;
	if ((len = readlink(data->path, data->sym_path, RL_BUFSIZE)) != -1)
		data->sym_path[len] = '\0';
}

static void			get_type(t_args *args_ch)
{
	int				type;

	type = args_ch->data.type;
	if ((TYPE_LNK & type) == TYPE_LNK)
	{
		args_ch->data.lnk = 1;
		get_sym_path(args);
	}
	else if ((TYPE_REG & type) == TYPE_REG)
		args_ch->data.reg = 1;
	else if ((TYPE_DIR & type) == TYPE_DIR)
		args_ch->data.dir = 1;
	else if ((TYPE_WHT & type) == TYPE_WHT)
		args_ch->data.wht = 1;
	else if ((TYPE_IFO & type) == TYPE_IFO)
		args_ch->data.ifo = 1;
	else if ((TYPE_SOCK & type) == TYPE_SOCK)
		args_ch->data.sock = 1;
	else if ((TYPE_CHR & type) == TYPE_CHR)
		args_ch->data.chr = 1;
	if ((TYPE_BLK & type) == TYPE_BLK)
		args_ch->data.blk = 1;
}

static void			get_user_group(t_lsbox *lsbox, t_args *args_ch, struct stat *func)
{
	struct passwd	*passwd;
	struct group	*group;

	if ((passwd = getpwuid(func->st_uid)))
		(args_ch->data.user = ft_strdup(passwd->pw_name));
	else
		args_ch->data.user = ft_itoa(func->st_uid);
	if (!args_ch->data.user)
		args_ch->data.user = lsbox->malloc_failed;
	if ((group = getgrgid(func->st_gid)))
		args_ch->data.group = ft_strdup(group->gr_name);
	else
		args_ch->data.group = ft_itoa(func->st_gid);
	if (!args_ch->data.group)
		args_ch->data.group = lsbox->malloc_failed;
}

void				read_f(t_lsbox *lsbox, t_args *args_ch, struct stat *func)
{
	lsbox->total_blocks += func->st_blocks;
	args_ch->data.ino = func->st_ino;
	args_ch->data.mode = func->st_mode;
	args_ch->data.type = func->st_mode;
	args_ch->data.links = func->st_nlink;
	get_user_group(lsbox, args, func);
	args_ch->data.rdev = func->st_rdev;
	args_ch->data.size = func->st_size;
	args_ch->data.c_time = func->st_ctimespec.tv_sec;
	args_ch->data.t_time = func->st_mtimespec.tv_sec;
	args_ch->data.u_time = func->st_atimespec.tv_sec;
	args_ch->data.up_u_time = func->st_birthtimespec.tv_sec;
	get_type(args);
}

void				attributes(t_lsbox *lsbox)
{
	t_arg_ch			*arg_ch;
	struct stat			func;

	arg_ch = lsbox->current_arg_ch;
	while (arg_ch)
	{
		if (!lstat(arg_ch->data.path, &func))
			read_f(lsbox, arg_ch, &func);
		else
			arg_ch->data.n_file = 1;
		arg_ch = arg_ch->next;
	}
}
