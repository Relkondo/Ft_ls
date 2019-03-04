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
	t_attr			*attr;

	attr = &args_ch->attr;
	if ((len = readlink(attr->path, attr->sym_path, RL_BUFSIZE)) != -1)
		attr->sym_path[len] = '\0';
}

static void			get_type(t_args *args_ch)
{
	int				type;

	type = args_ch->attr.type;
	if ((TYPE_LNK & type) == TYPE_LNK)
	{
		args_ch->attr.lnk = 1;
		get_sym_path(args);
	}
	else if ((TYPE_REG & type) == TYPE_REG)
		args_ch->attr.reg = 1;
	else if ((TYPE_DIR & type) == TYPE_DIR)
		args_ch->attr.dir = 1;
	else if ((TYPE_WHT & type) == TYPE_WHT)
		args_ch->attr.wht = 1;
	else if ((TYPE_IFO & type) == TYPE_IFO)
		args_ch->attr.ifo = 1;
	else if ((TYPE_SOCK & type) == TYPE_SOCK)
		args_ch->attr.sock = 1;
	else if ((TYPE_CHR & type) == TYPE_CHR)
		args_ch->attr.chr = 1;
	if ((TYPE_BLK & type) == TYPE_BLK)
		args_ch->attr.blk = 1;
}

static void			get_user_group(t_lsbox *lsbox, t_args *args_ch, struct stat *func)
{
	struct passwd	*passwd;
	struct group	*group;

	if ((passwd = getpwuid(func->st_uid)))
		(args_ch->attr.user = ft_strdup(passwd->pw_name));
	else
		args_ch->attr.user = ft_itoa(func->st_uid);
	if (!args_ch->attr.user)
		args_ch->attr.user = lsbox->malloc_failed;
	if ((group = getgrgid(func->st_gid)))
		args_ch->attr.group = ft_strdup(group->gr_name);
	else
		args_ch->attr.group = ft_itoa(func->st_gid);
	if (!args_ch->attr.group)
		args_ch->attr.group = lsbox->malloc_failed;
}

void				read_f(t_lsbox *lsbox, t_args *args_ch, struct stat *func)
{
	lsbox->total_blocks += func->st_blocks;
	args_ch->attr.ino = func->st_ino;
	args_ch->attr.mode = func->st_mode;
	args_ch->attr.type = func->st_mode;
	args_ch->attr.links = func->st_nlink;
	get_user_group(lsbox, args, func);
	args_ch->attr.rdev = func->st_rdev;
	args_ch->attr.size = func->st_size;
	args_ch->attr.c_time = func->st_ctimespec.tv_sec;
	args_ch->attr.t_time = func->st_mtimespec.tv_sec;
	args_ch->attr.u_time = func->st_atimespec.tv_sec;
	args_ch->attr.up_u_time = func->st_birthtimespec.tv_sec;
	get_type(args);
}

void				attributes(t_lsbox *lsbox)
{
	t_arg_ch			*arg_ch;
	struct stat			func;

	arg_ch = lsbox->current_arg_ch;
	while (arg_ch)
	{
		if (!lstat(arg_ch->attr.path, &func))
			read_f(lsbox, arg_ch, &func);
		else
			arg_ch->attr.n_file = 1;
		arg_ch = arg_ch->next;
	}
}
