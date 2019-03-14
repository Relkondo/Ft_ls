/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:42:04 by scoron            #+#    #+#             */
/*   Updated: 2019/03/06 19:59:18 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>

static void	get_sym_path(t_lsbox *lsbox, t_args *args, struct stat *st_attr)
{
	int				len;
	t_attr			*attr;

	attr = &args->attr;
	if ((len = readlink(attr->path, attr->sym_path, RL_BUFSIZE)) != -1)
		attr->sym_path[len] = '\0';
	if (!(lsbox->opt.cap_r) && !lstat(args->attr.sym_path, st_attr))
		if ((TYPE_DIR & st_attr->st_mode) == TYPE_DIR)
			args->attr.dir = 1;
}

static void	get_type(t_lsbox *lsbox, t_args *args, struct stat *st_attr)
{
	int				type;

	type = args->attr.type;
	if ((TYPE_LNK & type) == TYPE_LNK)
	{
		args->attr.lnk = 1;
		get_sym_path(lsbox, args, st_attr);
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

static void	get_user_group(t_lsbox *lsbox, t_args *args, struct stat *st_attr)
{
	struct passwd	*passwd;
	struct group	*group;

	if ((passwd = getpwuid(st_attr->st_uid)))
		args->attr.user = ft_strdup(passwd->pw_name);
	else
		args->attr.user = ft_itoa(st_attr->st_uid);
	if (!args->attr.user)
		ls_error(lsbox, "get attr.user failed");
	if ((group = getgrgid(st_attr->st_gid)))
		args->attr.group = ft_strdup(group->gr_name);
	else
		args->attr.group = ft_itoa(st_attr->st_gid);
	if (!args->attr.group)
		ls_error(lsbox, "get attr.group failed");
}

void		read_f(t_lsbox *lsbox, t_args *args, struct stat *st_attr)
{
	lsbox->total_blocks += st_attr->st_blocks;
	args->attr.ino = st_attr->st_ino;
	args->attr.mode = st_attr->st_mode;
	args->attr.type = st_attr->st_mode;
	args->attr.links = st_attr->st_nlink;
	get_user_group(lsbox, args, st_attr);
	args->attr.rdev = st_attr->st_rdev;
	args->attr.size = st_attr->st_size;
	args->attr.c_time = st_attr->st_ctimespec.tv_sec;
	args->attr.t_time = st_attr->st_mtimespec.tv_sec;
	args->attr.u_time = st_attr->st_atimespec.tv_sec;
	args->attr.cap_u_time = st_attr->st_birthtimespec.tv_sec;
	get_type(lsbox, args, st_attr);
}

void		register_attr(t_lsbox *lsbox)
{
	t_args				*args;
	struct stat			st_attr;

	args = lsbox->current_args;
	while (args)
	{
		if (!lstat(args->attr.path, &st_attr))
			read_f(lsbox, args, &st_attr);
		else
			args->attr.no_file = 1;
		args = args->next;
	}
}
