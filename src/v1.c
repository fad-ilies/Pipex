/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:22 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/04 00:56:06 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(t_cmd *cmd)
{
	int		i;
	char	*path;
	char	**tab;

	i = 0;
	path = NULL;
	while (cmd->env && cmd->env[i])
	{
		if (ft_strncmp(cmd->env[i], "PATH=", 5) == 0)
			path = cmd->env[i];
		i++;
	}
	if (!path)
		return (NULL);
	tab = ft_split(path + 5, ':');
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
	char	**env_path;
	char	*path;

	i = 1;
	env_path = get_path(cmd);
	if (!env_path || !*env_path)
		return (ft_putstr_fd("PATH not found\n", STDERR_FILENO), NULL);
	if (!s || !*s)
		return (free_tab(env_path), ft_putstr_fd("Command not found\n", STDERR_FILENO), NULL);
	j = 0;
	while (env_path[j])
	{
		path = ft_strjoin2(env_path[j], s);
		if (path)
		{
			if (access(path, F_OK | X_OK) == 0)
				return (free_tab(env_path), path);
			free(path);
		}
		j++;
	}
	return (free_tab(env_path), perror(s), NULL);
}
