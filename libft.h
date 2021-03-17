/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:28:52 by mel-idri          #+#    #+#             */
/*   Updated: 2021/03/03 15:57:27 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "libft_typedefs.h"

# define GNL_BUFF_SIZE 50
# define BUFF_SIZE 4096

# ifndef EXIT_ON_ALLOC_FAIL
#  define EXIT_ON_ALLOC_FAIL 0
# endif

/*
** Memory
*/
void		*ft_malloc(size_t size);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memdup(void *src, size_t n);
void		*ft_realloc(void *addr, size_t old_size, size_t new_size);

/*
** String
*/
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strdup_free(const char **s);
int			ft_strequ(char const *s1, char const *s2);
char		*ft_strglue(char const *s1, char glue, char const *s2);
size_t		ft_strichr(const char *s, int c);
size_t		ft_strings_array_length(char **arr);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free(char const *s1, char const *s2, int a, int b);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
void		ft_strrev(char *s);
int			get_next_line(const int fd, char **line);
void		ft_free_strings_array(char **array);

/*
**	Chars
*/
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isspace(int c);

/*
**	Numbers
*/
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
int			ft_nbrlen(__uint128_t unbr);
int			ft_nbrlen_base(unsigned long long n, int base);
int			ft_max(int nbr1, int nbr2);
long long	ft_power(int nbr, int exp);

/*
**	Printing
*/
int			ft_putchar(char c);
int			ft_putnchar(char c, int n);
int			ft_putstr(char const *str);
int			ft_putendl(char const *s);
int			ft_putnbr(int n);
int			ft_putunbr(unsigned long long n);
int			ft_putunbr_base(unsigned long long n, int base, int is_upper);
int			ft_putchar_fd(char c, int fd);
int			ft_putnchar_fd(char c, int n, int fd);
int			ft_putstr_fd(char const *s, int fd);
int			ft_putendl_fd(char const *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putunbr_fd(unsigned long long n, int fd);
int			ft_putunbr_base_fd(unsigned long long n, int base, int is_upper,
				int fd);
int			ft_write_buff(char *str, size_t size, int fd);
void		ft_flush_buff(int fd);
int			ft_printf(int fd, char *format, ...);

/*
**	List
*/
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem),
				void (*del)(void *, size_t));
t_list		*ft_lstsearch(t_list *lst, int (*f)(t_list *l));
void		ft_autofree_all(void);
void		*ft_autoalloc(size_t size);
t_queue		*ft_queue_new(void);
void		ft_enqueue(t_queue *queue, void *content, size_t content_size);
t_list		*ft_dequeue(t_queue *queue);

/*
** Bigint
*/
t_bigint	*ft_bigint_new(unsigned int size);
t_bigint	*ft_bigint_add(t_bigint *a, t_bigint *b);
t_bigint	*ft_bigint_mult(t_bigint *a, t_bigint *b);
t_bigint	*ft_bigint_from_uint128(__uint128_t unbr);
t_bigint	*ft_bigint_power(unsigned int b, unsigned int exp);
int			ft_bigint_print(t_bigint *bg_int, int fd);
int			ft_bigint_is_zero(t_bigint *bg_int);

/*
** Vector
*/
t_vector	*ft_vector_new(void);
int			ft_vector_init(t_vector *vector);
t_vector	*ft_vector_new_capacity(size_t capacity);
int			ft_vector_init_capacity(t_vector *vector, size_t capacity);
int			ft_vector_add(t_vector *vector, void *content, size_t content_size);
int			ft_vector_add_at(t_vector *vector, size_t index,
				void *content, size_t content_size);
int			ft_vector_remove_at(t_vector *vector, size_t index,
				void (*del)(void *content, size_t content_size));
int			ft_vector_realloc(t_vector *vector, size_t new_capacity);
void		ft_vector_free(t_vector *vec, t_bool free_vec,
				void (*del)(void *content, size_t content_size));

#endif
