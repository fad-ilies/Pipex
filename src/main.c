/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:29:31 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/29 19:29:15 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	init(int ac, char **av, char **env)
{
	t_cmd	cmd;

	cmd.env = env;
	cmd.av = av;
	cmd.pathname = get_cmd(&cmd);
	cmd.infile = av[1];
	cmd.outfile = av[ac - 1];
	cmd.len = ac - 3;
	cmd.pid = malloc(sizeof(pid_t) * cmd.len);
	return (cmd);
}

int	main(int ac, char **av, char **env)
{
	t_cmd	cmd;

	(void)ac;
	cmd = init(ac, av, env);
	// create_child(&cmd);
	// create_pipe();
	pipe_dad();
}