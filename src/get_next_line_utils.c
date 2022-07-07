/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:00:29 by aminoru-          #+#    #+#             */
/*   Updated: 2022/05/13 14:31:10 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (unsigned char)c;
	if (!s)
		return (0);
	while (*s != '\0' && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dest || !src)
		return (0);
	i = -1;
	if (size)
	{
		while (src[++i] && i < size - 1)
			dest[i] = src[i];
		dest[i] = '\0';
	}
	j = 0;
	while (src[j])
		j++;
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(&s3[0], s1, len_s1 + 1);
	ft_strlcpy(&s3[len_s1], s2, len_s2 + 1);
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	size = 0;
	while (s1[size])
		size++;
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}	
	ptr[size] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen_s;

	if (!s)
		return (NULL);
	strlen_s = 0;
	while (s[strlen_s])
		strlen_s++;
	if (start > strlen_s)
		return (ft_strdup(""));
	if (strlen_s - start >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((strlen_s - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), (len + 1));
	return (substr);
}
