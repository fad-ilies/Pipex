/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:45:28 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:48:00 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

#include "pipex_bonus.h"

void	child1_if(t_cmd *cmd)
{
	int	infile;

	infile = open(cmd->infile, O_RDONLY);
	if (infile < 0)
	{
		perror("Infile error");
		close(cmd->fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2 error (stdin)");
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 error (stdout)");
		exit(EXIT_FAILURE);
	}
	close(infile);
	close(cmd->fd[1]);
}

void	first_child_bonus(t_cmd *cmd, int i)
{
	char	*file;
	char	**commande;
	pid_t	child;

	i = 2;
	if (pipe(cmd->fd) == -1)
	{
		perror("pipe failure");
		exit(EXIT_FAILURE);
	}
	commande = ft_split(cmd->av[i], ' ');
	if (!commande || !commande[0])
		ft_error2(cmd, commande);
	child = fork();
	child_fail(cmd, child, commande);
	if (child == 0)
	{
		child1_if(cmd);
		file = cmd_check(cmd, commande[0]);
		ft_error3(file, commande);
		ft_exec(cmd, file, commande);
	}
	close(cmd->fd[1]);
	cmd->mid_fd = cmd->fd[0];
	free_tab(commande);
}

void	child2_of(t_cmd *cmd)
{
	int	outfile;

	outfile = open(cmd->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outfile < 0)
	{
		perror("outfile error");
		close(cmd->mid_fd);
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd->mid_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 error (stdin)");
		exit(EXIT_FAILURE);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2 error (stdout)");
		exit(EXIT_FAILURE);
	}
	close(cmd->mid_fd);
	close(outfile);
}

void	second_child_bonus(t_cmd *cmd, int i)
{
	char	*file;
	char	**commande;
	pid_t	child;

	commande = ft_split(cmd->av[i], ' ');
	ft_error2(cmd, commande);
	if (cmd->mid_fd < 0)
	{
		perror("cmd->mid_fd not initialized properly");
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
	child = fork();
	child_fail(cmd, child, commande);
	if (child == 0)
	{
		child2_of(cmd);
		file = cmd_check(cmd, commande[0]);
		ft_error3(file, commande);
		ft_exec(cmd, file, commande);
	}
	close(cmd->mid_fd);
	free_tab(commande);
	while (waitpid(-1, NULL, 0) != -1)
		;
}
