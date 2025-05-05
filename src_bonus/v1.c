/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:22 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:37:07 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**path_check(t_cmd *cmd)
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

char	*cmd_check(t_cmd *cmd, char *s)
{
	int		i;
	int		j;
	char	**env_path;
	char	*path;

	i = 1;
	env_path = path_check(cmd);
	if (!env_path || !*env_path)
		return (ft_putstr_fd("Path absent\n", 2), NULL);
	if (!s || !*s)
		return (free_tab(env_path), ft_putstr_fd("Commande inexistante\n", 2),
			NULL);
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
