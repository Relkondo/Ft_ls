/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:46:42 by scoron            #+#    #+#             */
/*   Updated: 2019/01/19 17:49:34 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (*(s + ++i))
		if (*(s + i) == (unsigned char)c)
			return ((char *)s + i);
	return (*((char *)s + i) == (unsigned char)c ? (char *)s + i : 0);
}

int		ft_strchri(const char *s, int c)
{
	int i;

	i = -1;
	while (*(s + ++i))
		if (*(s + i) == (unsigned char)c)
			return (i);
	return (*((char *)s + i) == (unsigned char)c ? i : -1);
}
