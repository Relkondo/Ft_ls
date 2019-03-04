/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:34:59 by scoron            #+#    #+#             */
/*   Updated: 2019/03/04 22:32:20 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>


# define BUFF_SIZE			92
# define O_a				(1 << 0)
# define O_b				(1 << 1)
# define O_c				(1 << 2)
# define O_d				(1 << 3)
# define O_e				(1 << 4)
# define O_f				(1 << 5)
# define O_g				(1 << 6)
# define O_h				(1 << 7)
# define O_i				(1 << 8)
# define O_j				(1 << 9)
# define O_k				(1 << 10)
# define O_l				(1 << 11)
# define O_m				(1 << 12)
# define O_n				(1 << 13)
# define O_o				(1 << 14)
# define O_p				(1 << 15)
# define O_q				(1 << 16)
# define O_r				(1 << 17)
# define O_s				(1 << 18)
# define O_t				(1 << 19)
# define O_u				(1 << 20)
# define O_v				(1 << 21)
# define O_w				(1 << 22)
# define O_x				(1 << 23)
# define O_y				(1 << 24)
# define O_z				(1 << 25)
# define O_A				(1 << 26)
# define O_B				(1 << 27)
# define O_C				(1 << 28)
# define O_D				(1 << 29)
# define O_E				(1 << 30)
# define O_F				(1 << 31)
# define O_G				(1 << 32)
# define O_H				(1 << 33)
# define O_I				(1 << 34)
# define O_J				(1 << 35)
# define O_K				(1 << 36)
# define O_L				(1 << 37)
# define O_M				(1 << 38)
# define O_N				(1 << 39)
# define O_O				(1 << 40)
# define O_P				(1 << 41)
# define O_Q				(1 << 42)
# define O_R				(1 << 43)
# define O_S				(1 << 44)
# define O_T				(1 << 45)
# define O_U				(1 << 46)
# define O_V				(1 << 47)
# define O_W				(1 << 48)
# define O_X				(1 << 49)
# define O_Y				(1 << 50)
# define O_Z				(1 << 51)
# define O_0				(1 << 52)
# define O_1				(1 << 53)
# define O_2				(1 << 54)
# define O_3				(1 << 55)
# define O_4				(1 << 56)
# define O_5				(1 << 57)
# define O_6				(1 << 58)
# define O_7				(1 << 59)
# define O_8				(1 << 60)
# define O_9				(1 << 61)
# define O_OTHER			(1 << 62)
# define O_ERROR			(1 << 63)

typedef	struct		s_chain
{
	struct s_chain	*next;
	struct s_chain	*previous;
	int				fd;
	char			*res;
}					t_chain;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, char c);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t n);
char				**ft_strdup_p(char **s);
char				**ft_strndup_p(char **s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int i, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
char				*ft_uitoa(uintmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_advanced_sort_wordtab(char **tab,
					int (*cmp)(char *, char *));
char				*ft_convert_base(char *nbr, char *base_from,
					char *base_to);
char				*ft_uconvert_base(char *nbr, char *base_from,
					char *base_to);
int					ft_any(char **tab, int (*f)(char*));
void				ft_swap(char **tab, int i);
intmax_t			ft_atoi_base(char *str, char *base);
uintmax_t			ft_uatoi_base(char *str, char *base);
char				*ft_strcutuntil(char **src, int c);
char				*ft_strshorten(char **s, int start, int len);
int					get_next_line(const int fd, char **line);
int					ft_power(int nbr, int power);
void				ft_putstab(char **tab);
void				ft_align_right(char *str);
unsigned long long	ft_opts(char **argv, char *all_opt);

#endif
