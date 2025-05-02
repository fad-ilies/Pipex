/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:45:28 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/02 16:59:51 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_if(t_cmd *cmd, int *infile)
{
	close(cmd->fd[0]);
	*infile = open(cmd->infile, O_RDONLY);
	if (*infile < 0)
	{
		ft_putstr_fd("infile error", 2);
		exit(EXIT_FAILURE);
	}
	if (dup2(*infile, STDIN_FILENO) == -1)
		ft_putstr_fd("dup2 inpute pipe error", 2);
	if (dup2(cmd->fd[1], STDOUT_FILENO) == -1)
		ft_putstr_fd("dup2 outpute pipe error", 2);
	close(*infile);
	close(cmd->fd[1]);
}

void	first_child(t_cmd *cmd)
{
	int		infile;
	char	*file;
	char	**commande;

	file = NULL;
	commande = ft_split(cmd->av[2], ' ');
	if (!commande)
		exit(EXIT_FAILURE);
	if (!commande[0])
	{
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
	file = get_cmd(cmd, commande[0]);
	if (!file)
	{
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
	child1_if(cmd, &infile);
	execve(file, commande, cmd->env);
	perror("Execve Failure1");
	free(file);
	exit(EXIT_FAILURE);
}

void	child2_of(t_cmd *cmd, int *outfile)
{
	close(cmd->fd[1]);
	*outfile = open(cmd->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (*outfile < 0)
	{
		ft_putstr_fd("outfile error", 2);
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd->fd[0], STDIN_FILENO) == -1)
		ft_putstr_fd("dup2 inpute pipe error", 2);
	close(cmd->fd[0]);
	if (dup2(*outfile, STDOUT_FILENO) == -1)
		ft_putstr_fd("dup2 outpute pipe error", 2);
	close(*outfile);
}

void	second_child(t_cmd *cmd)
{
	int		outfile;
	char	*file;
	char	**commande;
	int		i;

	i = 3;
	commande = ft_split(cmd->av[i], ' ');
	if (!commande)
		exit(EXIT_FAILURE);
	file = get_cmd(cmd, commande[0]);
	if (!file)
	{
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
	close(cmd->fd[1]);
	child2_of(cmd, &outfile);
	execve(file, commande, cmd->env);
	perror("Execve Failure2");
	free(file);
	free_tab(commande);
	exit(EXIT_FAILURE);
}
