
#include "libft.h"

static void			treat_opt(char c, unsigned long long *opt, char *all_opt)
{
	if (c >= 'a' && c <= 'z' && ft_strchr(all_opt, c))
		*opt |= (1 << (c - 97));
	else if (c >= 'A' && c <= 'Z' && ft_strchr(all_opt, c))
		*opt |= (1 << (c - 39));
	else if (c >= '0' && c <= '9' && ft_strchr(all_opt, c))
		*opt |= (1 << (c + 4));
/*	else if (ft_strchr(all_opt, c))
		*opt |= (1 << 62);
	else
		*opt |= (1 << 63);*/
}

unsigned long long	ft_options(char **argv, char *all_opt)
{
	unsigned long long	opt;
	char				*str;

	opt = 0;
	while (++argv && *argv)
	{
		str = *argv;
		if (!ft_strcmp(*argv, "--"))
			break ;
		else if (*str == '-')
		{
			while (++str && *str)
				treat_opt(*str, &opt, all_opt);
		}
	}
	return (opt);
}
