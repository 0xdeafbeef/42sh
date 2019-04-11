/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 02:59:56 by dmorgil           #+#    #+#             */
/*   Updated: 2018/12/30 12:34:52 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include "libft.h"

typedef struct		s_files
{
	char			*str;
	int				pos;
	int				end;
	int				fd;
	struct s_files	*next;
}					t_files;

int					get_next_line(const int fd, char **line);
#endif
