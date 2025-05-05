/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:28:00 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:36:52 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(t_cmd *cmd, int i)
{
	char	**commande;
	char	*file;

	commande = ft_split(cmd->av[i], ' ');
	file = cmd_check(cmd, commande[0]);
	if (!commande || !commande[0])
	{
		free_tab(commande);
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		perror("commande not found");
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
}

void	child_fail(t_cmd *cmd, pid_t child, char **commande)
{
	if (child == -1)
	{
		perror("fork failure");
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
}

void	ft_error2(t_cmd *cmd, char **commande)
{
	if (!commande || !commande[0])
	{
		free_tab(commande);
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		exit(EXIT_FAILURE);
	}
}

void	ft_error3(char *file, char **commande)
{
	if (!file)
	{
		perror("commande not found");
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
}
