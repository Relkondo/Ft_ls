/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:42:04 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 05:11:58 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>

static void			get_sym_path(t_args *args)
{
	int				len;
	t_attr			*attr;

	attr = &args->attr;
	if ((len = readlink(attr->path, attr->sym_path, RL_BUFSIZE)) != -1)
		attr->sym_path[len] = '\0';
}

static void			get_type(t_args *args)
{
	int				type;

	type = args->attr.type;
	if ((TYPE_LNK & type) == TYPE_LNK)
	{
		args->attr.lnk = 1;
		get_sym_path(args);
	}
	else if ((TYPE_REG & type) == TYPE_REG)
		args->attr.reg = 1;
	else if ((TYPE_DIR & type) == TYPE_DIR)
		args->attr.dir = 1;
	else if ((TYPE_WHT & type) == TYPE_WHT)
		args->attr.wht = 1;
	else if ((TYPE_IFO & type) == TYPE_IFO)
		args->attr.ifo = 1;
	else if ((TYPE_SOCK & type) == TYPE_SOCK)
		args->attr.sock = 1;
	else if ((TYPE_CHR & type) == TYPE_CHR)
		args->attr.chr = 1;
	if ((TYPE_BLK & type) == TYPE_BLK)
		args->attr.blk = 1;
}

static void			get_user_group(t_lsbox *lsbox, t_args *args, struct stat *func)
{
	struct passwd	*passwd;
	struct group	*group;

	if ((passwd = getpwuid(func->st_uid)))
		args->attr.user = ft_strdup(passwd->pw_name);
	else
		args->attr.user = ft_itoa(func->st_uid);
	if (!args->attr.user)
		ls_error(lsbox, "get attr.user failed");
	if ((group = getgrgid(func->st_gid)))
		args->attr.group = ft_strdup(group->gr_name);
	else
		args->attr.group = ft_itoa(func->st_gid);
	if (!args->attr.group)
		ls_error(lsbox, "get attr.group failed");
}

static void				read_f(t_lsbox *lsbox, t_args *args, struct stat *func)
{
	lsbox->total_blocks += func->st_blocks;
	args->attr.ino = func->st_ino;
	args->attr.mode = func->st_mode;
	args->attr.type = func->st_mode;
	args->attr.links = func->st_nlink;
	get_user_group(lsbox, args, func);
	args->attr.rdev = func->st_rdev;
	args->attr.size = func->st_size;
	args->attr.c_time = func->st_ctimespec.tv_sec;
	args->attr.t_time = func->st_mtimespec.tv_sec;
	args->attr.u_time = func->st_atimespec.tv_sec;
	args->attr.U_time = func->st_birthtimespec.tv_sec;
	get_type(args);
}

void				attributes(t_lsbox *lsbox)
{
	t_args				*args;
	struct stat			func;

	args = lsbox->current_args;
	while (args)
	{
		if (!lstat(args->attr.path, &func))
			read_f(lsbox, args, &func);
		else
			args->attr.no_file = 1;
		args = args->next;
	}
}
