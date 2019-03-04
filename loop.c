#include "ft_ls.h"
#include <sys/stat.h>

static bool			read_directory(t_read_dir *read_dir)
{
	if ((read_dir->lsbox->option.up_a && (ft_strcmp(read_dir->file->d_name, ".")
					&& ft_strcmp(read_dir->file->d_name, "..")))
			|| (read_dir->lsbox->option.a && read_dir->file->d_name[0] == '.')
			|| (read_dir->file->d_name[0] != '.'))
	{
		if (!(read_dir->tmp = create_args()))
		{
			free_args(read_dir->lsbox, &read_dir->head);
			return (false);
		}
		path(read_dir->lsbox, read_dir->tmp, read_dir->args->attr.path,
				read_dir->file->d_name);
		if (!read_dir->head)
			read_dir->head = read_dir->tmp;
		else
			read_dir->last_args_ch->next = read_dir->tmp;
		read_dir->last_args_ch = read_dir->tmp;
	}
	return (true);
}

static t_args_ch		*get_directory_contents(t_lsbox *lsbox, t_args_ch *args)
{
	t_read_dir		read_dir;

	read_dir.lsbox = lsbox;
	read_dir.args = args;
	read_dir.head = NULL;
	if (!(read_dir.directory = opendir(read_dir.args->attr.path)))
	{
		ft_printf("ft_ls: %s: Permission denied\n", read_dir.args->attr.str);
		return (NULL);
	}
	while ((read_dir.file = readdir(read_dir.directory)))
	{
		if (!read_directory(&read_dir))
			return (NULL);
	}
	closedir(read_dir.directory);
	return (read_dir.head);
}

static void			check_headers(t_lsbox *lsbox, t_args_ch *head)
{
	t_args_ch			*args;

	args = head;
	while (args && !lsbox->headers)
	{
		if (lsbox->option.up_r && args->attr.dir && !lsbox->option.d)
			lsbox->headers = 1;
		args = args->next;
	}
}

void				ls_loop(t_lsbox *lsbox, t_args_ch *args)
{
	t_args_ch			*head;
	t_args_ch			*tmp;

	check_headers(lsbox, args);
	print_path(lsbox, args, true);
	if (!(head = get_directory_contents(lsbox, args)))
		return ;
	lsbox->current_args_ch = head;
	get_attributes(lsbox);
	sort(lsbox);
	head = lsbox->current_args_ch;
	loop_valid_dir(lsbox, head);
	if (lsbox->option.up_r)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->attr.dir && ft_strcmp(tmp->attr.str, ".")
					&& ft_strcmp(tmp->attr.str, ".."))
				do_ls(lsbox, tmp);
			tmp = tmp->next;
		}
	}
	free_args(lsbox, &head);
}

