/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:29:31 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/02 02:16:44 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	init(int ac, char **av, char **env)
{
	t_cmd	cmd;

	cmd.env = env;
	cmd.av = av;
	cmd.pathname = NULL;
	cmd.infile = av[1];
	cmd.outfile = av[ac - 1];
	cmd.len = ac - 3;
	return (cmd);
}

int	main(int ac, char **av, char **env)
{
	t_cmd	cmd;
	int		i;
	pid_t	child1;
	pid_t	child2;

	(void)ac;
	i = 0;
	cmd = init(ac, av, env);
	if (pipe(cmd.fd) == -1)
		exit(EXIT_FAILURE);
	child1 = fork();
	if (child1 == 0)
		first_child(&cmd);
	child2 = fork();
	if (child2 == 0)
		second_child(&cmd);
	close(cmd.fd[0]);
	close(cmd.fd[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
	return (0);
}
