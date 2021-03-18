/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 08:56:12 by ylagtab           #+#    #+#             */
/*   Updated: 2021/03/18 10:04:52 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPEDEFS_H
# define LIBFT_TYPEDEFS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_alloc_list
{
	void				*address;
	struct s_alloc_list	*next;
}				t_alloc_list;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef	struct	s_queue
{
	t_list		*head;
	t_list		*tail;
	size_t		length;
}				t_queue;

typedef struct	s_list_fd
{
	int					fd;
	char				*rest;
	struct s_list_fd	*next;
}				t_list_fd;

typedef struct	s_element {
	void	*content;
	size_t	content_size;
}				t_element;

typedef struct	s_bigint
{
	char		*digits;
	unsigned	length;
}				t_bigint;

#endif
