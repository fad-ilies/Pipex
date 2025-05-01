/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:45:28 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/02 01:52:33 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_cmd *cmd)
{
	int		infile;
	char	*file = NULL;
	char	**commande;
	int		i;
	int		j;

	i = 2;
	j = 0;
	commande = ft_split(cmd->av[i], ' ');
	if (commande)
	{
		free_tab(commande);
		exit(EXIT_FAILURE);
	}
	close(cmd->fd[0]);
	infile = open(cmd->infile, O_RDONLY);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(cmd->fd[1], STDOUT_FILENO);
	close(cmd->fd[1]);
	file = get_cmd(cmd, commande[0]);
	if (!file)
	{
		free_tab(commande);
		exit(EXIT_FAILURE);	
	}
	execve(file, commande, cmd->env);
	// perror("Execve Failure1");
	free(file);
	exit(EXIT_FAILURE);
}

void	second_child(t_cmd *cmd)
{
	int		outfile;
	char	*file;
	char	**commande;
	int		i;
	int		j;

	i = 3;
	j = 0;
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
	outfile = open(cmd->outfile, O_WRONLY);
	dup2(cmd->fd[0], STDIN_FILENO);
	close(cmd->fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execve(file, commande, cmd->env);
	// perror("Execve Failure2");
	free(file);
	free_tab(commande);
	exit(EXIT_FAILURE);
}

