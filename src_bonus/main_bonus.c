/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:48:27 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:45:56 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_cmd	cmd;
	int		i;

	i = 2;
	if (ac < 5)
	{
		ft_putstr_fd("Error nbr args", 2);
		exit(EXIT_FAILURE);
	}
	cmd = cmd_init(ac, av, env);
	while (i)
	{
		if (i == 2)
			first_child_bonus(&cmd, i);
		else if (i == (ac - 2))
		{
			second_child_bonus(&cmd, i);
			break ;
		}
		else
			mid_child(&cmd, cmd.av[i]);
		i++;
	}
	return (0);
}
