/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:38:03 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/01 23:47:16 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i++] = '/';
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i++] = s2[j++];
	}
	new_str[i] = '\0';
	return (new_str);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t		len1;
// 	size_t		len2;
// 	char		*ptr;
// 	int			i;

// 	i = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	ptr = malloc(sizeof(char) * (len1 + len2 + 2));
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy(ptr, s1, len1 + len2 + 1);
// 	ptr[i++] = '/';
// 	ft_strlcat(ptr, s2, len1 + len2 + 1);
// 	return (ptr);
// }

void	free_tab(char **str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}