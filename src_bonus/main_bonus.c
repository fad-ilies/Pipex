/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:18:59 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/04 22:03:16 by ifadhli          ###   ########.fr       */
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
    pid_t   *pids;
    
	i = 0;
	cmd = init(ac, av, env);
    pids = malloc(sizeof(pid_t) * (cmd.len));
    if (!pids)
    {
        perror("malloc failure");
        exit(EXIT_FAILURE);
    }
	while (i < cmd.len)
	{
		if (pipe(cmd.fd) == -1)
		{
			perror("pipe ko");
			exit(EXIT_FAILURE);
		}
		cmd.pid = fork();
        if (cmd.pid == -1)
        {
            perror("fork failure");
            exit(EXIT_FAILURE);
        }
        pids[i] = cmd.pid;
		if (cmd.pid == 0)
		{
			if (i == 0)
				first_child(&cmd);
			else if (i == cmd.len - 1)
				second_child(&cmd);
            else
                mid_child(&cmd, cmd.av[i]);
            exit(EXIT_FAILURE);
		}
		else
		{
			close(cmd.fd[0]);
			close(cmd.fd[1]);
        }
        i++;
    }
    i = 0;
	while (i < cmd.len)
		waitpid(pids[i++], NULL, 0);
    free(pids);
}
