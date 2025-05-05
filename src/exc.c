/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:57:34 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:50:54 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_if(t_cmd *cmd)
{
	int	infile;

	infile = open(cmd->infile, O_RDONLY);
	if (infile < 0)
	{
		ft_putstr_fd("Infile error\n", 2);
		close(cmd->fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		ft_putstr_fd("dup2 inpute pipe error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd->fd[1], STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("dup2 outpute pipe error\n", 2);
		exit(EXIT_FAILURE);
	}
	close(infile);
	close(cmd->fd[1]);
}

void	first_child(t_cmd *cmd)
{
	char	*file;
	char	**commande;

	close(cmd->fd[0]);
	child1_if(cmd);
	commande = ft_split(cmd->av[2], ' ');
	file = cmd_check(cmd, commande[0]);
	if (!commande || !file)
	{
		free_tab(commande);
		close(cmd->fd[1]);
		exit(EXIT_FAILURE);
	}
	execve(file, commande, cmd->env);
	perror("execve failure");
	ft_putstr_fd("Command not found", 2);
	free(file);
	exit(EXIT_FAILURE);
}

void	child2_of(t_cmd *cmd)
{
	int	outfile;

	outfile = open(cmd->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (outfile < 0)
	{
		ft_putstr_fd("outfile error\n", 2);
		close(cmd->fd[0]);
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd->fd[0], STDIN_FILENO) == -1)
	{
		ft_putstr_fd("dup2 inpute pipe error\n", 2);
		exit(EXIT_FAILURE);
	}
	close(cmd->fd[0]);
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("dup2 inpute pipe error\n", 2);
		exit(EXIT_FAILURE);
	}
	close(outfile);
	close(cmd->fd[0]);
}

void	second_child(t_cmd *cmd)
{
	char	*file;
	char	**commande;

	close(cmd->fd[1]);
	child2_of(cmd);
	commande = ft_split(cmd->av[3], ' ');
	file = cmd_check(cmd, commande[0]);
	if (!commande || !file)
	{
		free_tab(commande);
		free(file);
		close(cmd->fd[0]);
		exit(EXIT_FAILURE);
	}
	execve(file, commande, cmd->env);
	perror("execve failure");
	ft_putstr_fd("Command not found", 2);
	free(file);
	free_tab(commande);
	exit(EXIT_FAILURE);
}
