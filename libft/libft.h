/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aplat <aplat@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:33:55 by aplat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 17:18:22 by aplat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include <errno.h>

char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,\
					const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int nb);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_countwords(const char *str, char c);
int					ft_wordlen(const char *s, char c);
int					ft_power(int nb, int power);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_str_is_printable(char *s);
int					ft_str_is_numeric(char *s);
int					ft_str_is_alpha(char *s);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_uppercase(char *str);
char				*ft_strcapitalize(char *s);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);

char				*ft_fstrjoin(const char **s1, const char **s2,\
					int free_s1, int free_s2);
int					get_next_line(const int fd, char **line);

void				aff_a(int ac, char *str);
void				aff_z(int ac, char *str);
void				ft_countdown();
void				ft_print_numbers();
void				hello();
void				maff_alpha();
void				maff_revalpha();
void				aff_first_param(int ac, char **str);
void				aff_last_param(int ac, char **str);
void				only_a();
void				only_z();

void				repeat_alpha(int ac, char **str);
void				search_and_replace(int ac, char **str);
void				ulstr(int ac, char **str);
void				rot_13(int ac, char **str);
void				rotone(int ac, char **str);
void				first_word(int ac, char **str);
void				ft_swap(int *a, int *b);
void				rev_print(int ac, char **str);

void				inter(int ac, char **str);
float				ft_powf(float nb, float power);

#endif
