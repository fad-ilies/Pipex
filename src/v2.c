/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:45:28 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/30 00:14:30 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_child(t_cmd *cmd)
{
	int		status;
	pid_t	pid;
	char	**tab;

	tab = cmd->av;
	cmd->pathname = get_cmd(cmd);
	pid = fork();
	printf("pid == %d\n", pid);
	if (pid == -1)
		perror("fork failure");
	else if (pid == 0)
	{
		printf("tour2\n");
		printf("cmd to find == %s\n", cmd->pathname);
		printf("tab[1] == %s\n", tab[1]);
		if (execve(cmd->pathname, &tab[1], cmd->env) == -1)
			perror("execve failure");
	}
	else
	{
		printf("tour 1\n");
		waitpid(pid, &status, 0);
	}
}

void	create_pipe(int fd[2])
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	write(STDOUT_FILENO, "Hello Pipe\n", 11);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}

void	pipe_dad(void)
{
	int		fd[2];
	int		status;
	pid_t	pid;
	char	c;

	pid = fork();
	if (pid == 0)
		create_pipe(fd);
	else
	{
		close(fd[1]);
		while (read(fd[0], &c, 1) > 0)
			write(STDOUT_FILENO, &c, 1);
		close(fd[0]);
		waitpid(pid, &status, 0);
	}
}
