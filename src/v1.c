/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:22 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/29 21:55:52 by ifadhli          ###   ########.fr       */
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
	return (tab);
}

char	*get_cmd(t_cmd *cmd)
{
	int		i;
	int		j;
	char	**str;
	char	*pathname;

	i = 1;
	str = get_path(cmd);
	if (!str)
		return(NULL);
	j = 0;
	while (str[j])
	{
		pathname = ft_strjoin2(str[j], cmd->av[i]);
		if (access(pathname, F_OK | X_OK) == 0)
			return (pathname);
		j++;
	}
	perror(cmd->av[i]);	
	return (NULL);
}

