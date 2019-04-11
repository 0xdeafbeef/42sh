/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 02:59:43 by dmorgil           #+#    #+#             */
/*   Updated: 2018/12/30 12:55:21 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/*
 ** Finding list by file descriptor. If found in head node return it;
 ** If it's not in head node, resume search in all nodes;
*/

t_files	*ft_find_list_by_fd(t_files **list, int fd, int rm)
{
	t_files			*tmp;
	t_files			*del;

	if (!(tmp = *list))
		return (NULL);
	if (tmp->fd == fd)
	{
		if (rm)
			*list = tmp->next;
		return (tmp);
	}
	while (tmp->next && tmp->next->fd != fd)
		tmp = tmp->next;
	if (tmp->next && tmp->next->fd == fd)
	{
		if (rm)
		{
			del = tmp->next;
			tmp->next = tmp->next->next;
		}
		return (tmp->next);
	}
	return (NULL);
}

/*
 ** If no file descriptor found, push new list to begin of lists
*/

t_files	*ft_push_front(t_files **list, int fd)
{
	t_files			*tmp;

	if (!(tmp = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	if (!(tmp->str = ft_strnew(BUFF_SIZE + 1)))
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = *list;
	tmp->pos = 0;
	if ((tmp->end = read(fd, tmp->str, BUFF_SIZE)) == -1)
	{
		free(tmp->str);
		free(tmp);
		return (NULL);
	}
	tmp->fd = fd;
	*list = tmp;
	return (tmp);
}

/*
 ** If i didn't found \n, i need to remember old str and allocate memory for
 ** new buffer size;
*/

int		ft_concat(t_files *list, int len)
{
	char			*tmp;
	int				readed;

	if (!(tmp = ft_strnew(BUFF_SIZE + (list->end - list->pos))))
		return (-1);
	ft_memcpy(tmp, list->str + list->pos, list->end - list->pos);
	free(list->str);
	if ((readed = read(list->fd, tmp + list->end - list->pos, BUFF_SIZE)) == -1)
		return (-1);
	list->str = tmp;
	list->end = list->end - list->pos + readed;
	list->pos = 0;
	if (!readed && len)
	{
		list->str[list->end] = '\n';
		list->end += (list->str[list->end - 1] == '\n') ? 0 : 1;
	}
	return (readed + ((len) ? 1 : 0));
}

/*
 ** pos - current position in line; end - end position in line, checking for \n
*/

int		ft_checker(t_files *curr, char **line)
{
	int				len;
	int				output;

	output = 1;
	while (1)
	{
		len = 0;
		while (len + curr->pos < curr->end && curr->str[curr->pos + len]
				!= '\n')
			len++;
		if ((len + curr->pos < curr->end))
			break ;
		if ((output = ft_concat(curr, len)) < 1)
			return (output);
	}
	if (!(*line = ft_strnew(len)))
		return (-1);
	*line = ft_memcpy(*line, curr->str + curr->pos, len);
	curr->pos += len + 1;
	return (1);
}

/*
 ** Finding fd in list, if no foun, try to push it in the lists, if line was
 ** readed return (1), free unused elems
*/

int		get_next_line(const int fd, char **line)
{
	static t_files	*head = 0;
	t_files			*curr;

	if (!(curr = ft_find_list_by_fd(&head, fd, 0)))
		if (!(curr = ft_push_front(&head, fd)))
			return (-1);
	if (ft_checker(curr, line) == 1)
		return (1);
	free(curr->str);
	free(ft_find_list_by_fd(&head, fd, 1));
	return (0);
}
