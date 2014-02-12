/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/02/12 03:22:30 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# include "libftprintf.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Convert a string to number
*/

int		ft_atoi(const char *str);

/*
** Makes zero a predefined number of characters
*/

void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);

/*
** Count the number of characters in a string
*/

size_t	ft_strlen(const char *s);
size_t	ft_strclen(const char *s, int c);
int		ft_tablen(char ****tab, int line);

/*
** Count the number of characters in a integer
*/

size_t	ft_ilen(int n);

/*
** search characters in a string
*/

void	*ft_memchr(const void *s, int c, size_t n);

/*
** Compares two memory spaces
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Copying a memory space to another
*/

void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);

/*
** Copying through temporary space
*/

void	*ft_memmove(void *s1, const void *s2, size_t n);

/*
** Replaces a character by the number of desired
*/

void	*ft_memset(void *b, int c, size_t len);

/*
** Concatenation of character strings
*/

char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *s1, const char *s2, size_t n);


int		ft_strcchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

/*
** Compare two string and returns the difference
*/

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** Copy a string in another
*/

char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);

/*
** Duplicating a character string
*/

char	*ft_strdup(const char *s1);

/*
** Returns the string for the first occurrence found
*/

char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/*
** Convert uppercase to lowercase and vice versa
*/

int		ft_tolower(int c);
int		ft_toupper(int c);

/*
** Allocates a memory space or destroyed
*/

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);

/*
** Create a character string, the empty or destroyed
*/

char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);

/*
** Treats the characters of a string through a given function
*/

void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** Allocates then processes the characters of a string with a given function
*/

char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/*
** Compares two strings lexicographically
*/

int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t n);

/*
** Cutting, seal and cleans a string
*/

void	ft_argtrim(char **str);
char	*ft_strins(char *s1, char *s2, size_t start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_strsplit(const char *s, char c);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s);

/*
** Converts a number to a string
*/

char	*ft_ctoa(int c);
char	*ft_ftoa(double n);
char	*ft_itoa(int n);
char	*ft_xtoa(int n, int on);
char	*ft_lsttoa(t_list *lst, int reverse);

/*
** Writing a string in the console
*/

void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putlst(t_list *lst, char *(*f)(int n), int reverse, int debug);

/*
** Writing a character in the console
*/

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar_loop(int c, int nbr);
void	ft_putchar_loop_fd(int c, int fd, int nbr);

/*
** Writing a number in the console
*/

void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);

/*
** Fonctions with free memory
*/

char	*ft_strfjoin1(char **s1, char *s2, int pfree);
char	*ft_strfjoin2(char *s1, char **s2, int pfree);
char	*ft_strfjoin(char **s1, char **s2, int pfree);
char	**ft_strfsplit(char **s, char c, int pfree);
char	*ft_strfsub(char **s, unsigned int start, size_t len, int pfree);
char	*ft_strftrim(char **s, int pfree);
int		ft_free_return(int ret, char **data);
void	ft_free_strtab(char ***str);

/*
** Handling chained list
*/

t_list	*ft_lstnew(const void *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstaddend(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstcmp(t_list *lst, char *str);
size_t	ft_lstlen(t_list *lst);

#endif
