/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <scoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 12:40:04 by scoron            #+#    #+#             */
/*   Updated: 2019/03/03 12:40:06 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	opt_error(t_lsbox *lsbox, char c)
{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		write(2, &c, 1);
		ft_putstr_fd("\nusage: ./ft_ls [", 2);
		ft_putstr_fd(ALL_OPT, 2);
		ls_error(lsbox, "] [file ...]");
}

int		count_opt(t_lsbox *lsbox)
{
		int					nb_opt;
		char				**argv;

		argv = lsbox->argv;
		nb_opt = 0;
		while (*argv && **argv == '-' && *(*argv + 1))
		{
				nb_opt++;
				if (!(ft_strcmp(*argv, "--")))
					break;
				argv++;
		}
		return (nb_opt);
}

void	fetch(t_lsbox *lsbox, char c)
{
	lsbox->opt.a += (c == 'a') ? 1 : 0;
	lsbox->opt.c += (c == 'c') ? 1 : 0;
	lsbox->opt.d += (c == 'd') ? 1 : 0;
	lsbox->opt.f += (c == 'f') ? 1 : 0;
	lsbox->opt.g += (c == 'g') ? 1 : 0;
	lsbox->opt.i += (c == 'i') ? 1 : 0;
	lsbox->opt.l += (c == 'l') ? 1 : 0;
	lsbox->opt.o += (c == 'o') ? 1 : 0;
	lsbox->opt.p += (c == 'p') ? 1 : 0;
	lsbox->opt.r += (c == 'r') ? 1 : 0;
	lsbox->opt.t += (c == 't') ? 1 : 0;
	lsbox->opt.u += (c == 'u') ? 1 : 0;
	lsbox->opt.x += (c == 'x') ? 1 : 0;
	lsbox->opt.A += (c == 'A') ? 1 : 0;
	lsbox->opt.F += (c == 'F') ? 1 : 0;
	lsbox->opt.G += (c == 'G') ? 1 : 0;
	lsbox->opt.N += (c == 'N') ? 1 : 0;
	lsbox->opt.R += (c == 'R') ? 1 : 0;
	lsbox->opt.S += (c == 'S') ? 1 : 0;
	lsbox->opt.T += (c == 'T') ? 1 : 0;
	lsbox->opt.U += (c == 'U') ? 1 : 0;
	lsbox->opt.one += (c == '1') ? 1 : 0;
}

void	init_fetch(t_lsbox *lsbox)
{
	lsbox->opt.a =  0;
	lsbox->opt.c =  0;
	lsbox->opt.d =  0;
	lsbox->opt.f =  0;
	lsbox->opt.g =  0;
	lsbox->opt.i =  0;
	lsbox->opt.l =  0;
	lsbox->opt.o =  0;
	lsbox->opt.p =  0;
	lsbox->opt.r =  0;
	lsbox->opt.t =  0;
	lsbox->opt.u =  0;
	lsbox->opt.x =  0;
	lsbox->opt.A =  0;
	lsbox->opt.F =  0;
	lsbox->opt.G =  0;
	lsbox->opt.N =  0;
	lsbox->opt.R =  0;
	lsbox->opt.S =  0;
	lsbox->opt.T =  0;
	lsbox->opt.U =  0;
	lsbox->opt.one =  0;
}

void	register_options(t_lsbox *lsbox)
{
		char	**argv_opt;
		char	*opt;

		if (!lsbox->argv_opt)
				return ;
		init_fetch(lsbox);
		argv_opt = lsbox->argv_opt;
		while (*argv_opt && **argv_opt)
		{
			opt = *argv_opt;
			while (++opt && *opt)
			{
				if (ft_strchr(ALL_OPT, *opt))
					fetch(lsbox, *opt);
				else
					opt_error(lsbox, *opt);
			}
			argv_opt++;
		}
}
