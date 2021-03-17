/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:02:02 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/15 19:46:12 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list_fd	*lstadd_fd(t_list_fd **alst, int fd, char *rest)
{
	t_list_fd	*node;
	t_list_fd	*tmp;

	if (!alst || (node = (t_list_fd *)ft_malloc(sizeof(t_list_fd))) == NULL)
		return (NULL);
	node->fd = fd;
	if ((node->rest = ft_strdup((const char *)rest)) == NULL)
	{
		ft_memdel((void **)&node);
		return (NULL);
	}
	node->next = NULL;
	if (*alst == NULL || fd < (*alst)->fd)
	{
		node->next = *alst;
		*alst = node;
		return (node);
	}
	tmp = *alst;
	while (tmp->next && fd > tmp->next->fd)
		tmp = tmp->next;
	node->next = tmp->next;
	tmp->next = node;
	return (node);
}

static int			lstdel_fd(t_list_fd **alst, int fd)
{
	t_list_fd	*tmp;
	t_list_fd	*prev;

	if ((*alst) && (*alst)->fd == fd)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_memdel((void **)&tmp);
		return (-1);
	}
	tmp = *alst;
	while (tmp)
	{
		if (tmp->fd >= fd)
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL || tmp->fd != fd)
		return (-1);
	prev->next = tmp->next;
	ft_strdel((char **)&(tmp->rest));
	ft_memdel((void **)&tmp);
	return (-1);
}

static t_list_fd	*lstsearch_fd(t_list_fd *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		if (lst->fd > fd)
			return (NULL);
		lst = lst->next;
	}
	return (NULL);
}

static int			readline(char **l, char **p, t_list_fd **t, t_list_fd **f_l)
{
	char				buf[GNL_BUFF_SIZE + 1];
	int					ret;

	if (read((*t)->fd, buf, 0) < 0)
		return (-1);
	ret = 0;
	if ((*l = ft_strdup_free((const char **)&((*t)->rest))) == NULL)
		return (lstdel_fd(f_l, (*t)->fd));
	while (((*p = ft_strchr(*l, '\n')) == NULL)
			&& ((ret = read((*t)->fd, buf, GNL_BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		if ((*l = ft_strjoin_free(*l, buf, 1, 0)) == NULL)
		{
			ft_strdel(l);
			return (lstdel_fd(f_l, (*t)->fd));
		}
	}
	if (**l == '\0' && ret == 0)
	{
		lstdel_fd(f_l, (*t)->fd);
		ft_strdel(l);
		return (0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd	*fd_lst;
	t_list_fd			*tmp;
	char				*pos;
	int					ret;

	if (fd < 0 || line == NULL || GNL_BUFF_SIZE < 0)
		return (-1);
	if ((tmp = lstsearch_fd(fd_lst, fd)) == NULL)
		if ((tmp = lstadd_fd(&fd_lst, fd, "")) == NULL)
			return (-1);
	if ((ret = readline(line, &pos, &tmp, &fd_lst)) <= 0)
		return (ret == 0 ? 0 : -1);
	if (pos)
		*pos = '\0';
	if (pos != NULL && *(pos + 1) != '\0')
		tmp->rest = ft_strdup(pos + 1);
	else
		tmp->rest = ft_strdup("");
	if (tmp->rest == NULL || !(*line = ft_strdup_free((const char **)line)))
	{
		lstdel_fd(&fd_lst, fd);
		ft_strdel(line);
		return (-1);
	}
	return (1);
}
