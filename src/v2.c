/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:45:28 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/02 02:18:07 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_if(t_cmd *cmd, int *infile)
{
	close(cmd->fd[0]);
	*infile = open(cmd->infile, O_RDONLY);
	if (*infile < 0)
		exit(EXIT_FAILURE);
	dup2(*infile, STDIN_FILENO);
	dup2(cmd->fd[1], STDOUT_FILENO);
	close(*infile);
	close(cmd->fd[1]);
}

void	first_child(t_cmd *cmd)
{
	int		infile;
	char	*file;
	char	**commande;
	int		i;

	file = NULL;
	i = 2;
	commande = ft_split(cmd->av[i], ' ');
	if (commande)
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
	*outfile = open(cmd->outfile, O_WRONLY);
	if (outfile < 0)
		exit(EXIT_FAILURE);
	dup2(cmd->fd[0], STDIN_FILENO);
	close(cmd->fd[0]);
	dup2(*outfile, STDOUT_FILENO);
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
	if (commande == 0)
		exit(EXIT_FAILURE);
	file = get_cmd(cmd, commande[0]);
	if (file == 0)
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
