/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:46:22 by mucelik           #+#    #+#             */
/*   Updated: 2023/05/13 15:51:57 by mucelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//'line' dizisindeki ilk satırı geri döndürür
char	*newlinedenonce(char *line)
{
	char	*neww;
	int		i;

	i = 0;
	if (!line[i])
		return (0);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	neww = (char *)malloc(sizeof(char) * (i + 2));
	if (!neww)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		neww[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		neww[i] = line[i];
		i++;
	}
	neww[i] = '\0';
	return (neww);
}

//'line' dizisindeki son satırı keser ve geri kalanını döndürür
char	*newlinedensonra(char *line)
{
	char	*neww;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	neww = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!neww)
		return (0);
	i++;
	while (line[i])
		neww[j++] = line[i++];
	neww[j] = '\0';
	free(line);
	return (neww);
}

//fd ile bir satırı BUFFER_SIZE ile okur 
char	*put_line(int fd, char *line)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	i = 1;
	while (!ft_strchr(line, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (0);
		}
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
	}
	free (buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*a;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = put_line(fd, line);
	if (line)
	{
		a = newlinedenonce(line);
		line = newlinedensonra(line);
		return (a);
	}
	return (0);
}

/*
int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("test.txt", O_RDONLY);
	ptr = get_next_line(fd);
	while (ptr)
	{
		printf("%s", ptr);
		ptr = get_next_line(fd);
	}
	return (0);
}
*/