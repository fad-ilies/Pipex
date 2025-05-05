/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:29:31 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:49:44 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_main(t_cmd cmd)
{
	pid_t	child1;
	pid_t	child2;
	int		i;

	i = 0;
	if (pipe(cmd.fd) == -1)
	{
		perror("pipe ko");
		exit(EXIT_FAILURE);
	}
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

int	main(int ac, char **av, char **env)
{
	t_cmd	cmd;
	int		i;

	i = 0;
	cmd = cmd_init(ac, av, env);
	if (ac == 5)
		check_main(cmd);
	else
		ft_putstr_fd("Command not found\n", 2);
	return (0);
}
