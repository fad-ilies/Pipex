/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:15:13 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:36:38 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	redirecton_mid(t_cmd *cmd)
{
	if (dup2(cmd->mid_fd, STDIN_FILENO) == -1)
	{
		ft_putstr_fd("dup2 inpute mid_child pipe error\n", 2);
		exit(EXIT_FAILURE);
	}
	close(cmd->mid_fd);
	if (dup2(cmd->fd[1], STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("dup2 output pipe error\n", 2);
		exit(EXIT_FAILURE);
	}
	close(cmd->fd[1]);
	close(cmd->fd[0]);
}

void	mid_child(t_cmd *cmd, char *mid)
{
	char	*file;
	char	**commande;
	pid_t	child;

	if (pipe(cmd->fd) == -1)
	{
		perror("pipe failure");
		exit(EXIT_FAILURE);
	}
	commande = ft_split(mid, ' ');
	ft_error2(cmd, commande);
	child = fork();
	child_fail(cmd, child, commande);
	if (child == 0)
	{
		redirecton_mid(cmd);
		file = cmd_check(cmd, commande[0]);
		ft_error3(file, commande);
		ft_exec(cmd, file, commande);
	}
	parent_process(cmd);
	free_tab(commande);
}
