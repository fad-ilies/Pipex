/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:22 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/02 02:17:24 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(t_cmd *cmd)
{
	int		i;
	char	*str;
	char	*path;
	char	**tab;

	i = 0;
	path = "PATH=";
	while (cmd->env[i])
	{
		if (ft_strncmp(cmd->env[i], path, 5) == 0)
			str = cmd->env[i];
		i++;
	}
	tab = ft_split(str + 5, ':');
	if (!tab)
	{
		free_tab(tab);
		return (NULL);
	}
	return (tab);
}

char	*get_cmd(t_cmd *cmd, char *s)
{
	int		i;
	int		j;
	char	**str;
	char	*path;

	i = 1;
	str = get_path(cmd);
	if (!str)
		return (perror("str"), NULL);
	j = 0;
	while (str[j])
	{
		path = ft_strjoin2(str[j], s);
		if (path)
		{
			if (access(path, F_OK | X_OK) == 0)
			{
				free_tab(str);
				return (path);
			}
			free(path);
		}
		j++;
	}
	return (free_tab(str), perror(s), NULL);
}
