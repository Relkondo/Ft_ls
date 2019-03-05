/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:45:10 by scoron            #+#    #+#             */
/*   Updated: 2019/03/05 07:26:29 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/xattr.h>

static char			*get_str(int value)
{
	if (value == 1)
		return (PER_1);
	if (value == 2)
		return (PER_2);
	if (value == 3)
		return (PER_3);
	if (value == 4)
		return (PER_4);
	if (value == 5)
		return (PER_5);
	if (value == 6)
		return (PER_6);
	if (value == 7)
		return (PER_7);
	return (PER_0);
}

static char			get_type(t_args *args)
{
	if (args->attr.blk)
		return (PER_BLK);
	if (args->attr.sock)
		return (PER_SOCK);
	if (args->attr.ifo)
		return (PER_IFO);
	if (args->attr.chr)
		return (PER_CHR);
	if (args->attr.dir)
		return (PER_DIR);
	if (args->attr.reg)
		return (PER_REG);
	if (args->attr.lnk)
		return (PER_LNK);
	return (' ');
}

static char			get_acl(t_args *args)
{
	acl_t			acl;

	if (listxattr(args->attr.path, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	else if (!(acl = acl_get_file(args->attr.path, ACL_TYPE_EXTENDED)))
		return (' ');
	acl_free(acl);
	return ('+');
}

static void			swap_exec_char(t_args *args, int i, char *exec_char)
{
	if (i == 2 && args->attr.mode & S_ISUID)
		*exec_char = ((args->attr.mode & S_IXUSR) ? 's' : 'S');
	if (i == 1 && args->attr.mode & S_ISGID)
		*exec_char = ((args->attr.mode & S_IXGRP) ? 's' : 'S');
	if (i == 0 && args->attr.mode & S_ISVTX)
		*exec_char = ((args->attr.mode & S_IXOTH) ? 't' : 'T');
}

void				type(t_lsbox *lsbox, t_args *args)
{
	int				i;
	int				type;
	char			*str;
	char			*tmp;

	i = 3;
	type = args->attr.type;
	(void)lsbox;
	if ((str = (char *)malloc(sizeof(char) * 12)))
	{
		tmp = str;
		*(tmp++) = get_type(args);
		while (i--)
		{
			ft_strcpy(tmp, get_str((type >> (3 * i)) & 7));
			swap_exec_char(args, i, tmp + 2);
			tmp += 3;
		}
		*(tmp++) = get_acl(args);
		*tmp = '\0';
		ft_printf("%-12s", str);
		free(str);
	}
	else
		ls_error(lsbox, "malloc type failed\n");
}
