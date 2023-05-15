/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelik <mucelik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:46:51 by mucelik           #+#    #+#             */
/*   Updated: 2023/05/13 11:32:35 by mucelik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Girilen char pointerinin uzunluğunu döndürür
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

//s dizininde gördüğü ilk c karakterinden sonrasını döndürür
char	*ft_strchr(const char	*s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

//iki diziyi birleştirip yeni bir dizi olarak geri döndürür
char	*ft_strjoin(char *d_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!d_line)
	{
		d_line = (char *)malloc(1 * sizeof(char));
		d_line[0] = '\0';
	}
	if (!d_line || !buff)
		return (0);
	str = malloc(sizeof(char) * ((ft_strlen(d_line) + ft_strlen(buff)) + 1));
	if (str == 0)
		return (0);
	i = -1;
	j = 0;
	if (d_line)
		while (d_line[++i] != '\0')
			str[i] = d_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(d_line) + ft_strlen(buff)] = '\0';
	free(d_line);
	return (str);
}
