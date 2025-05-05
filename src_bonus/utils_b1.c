/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:27:28 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:36:45 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i++] = '/';
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i++] = s2[j++];
	}
	new_str[i] = '\0';
	return (new_str);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_cmd	cmd_init(int ac, char **av, char **env)
{
	t_cmd	cmd;

	cmd.env = env;
	cmd.av = av;
	cmd.pathname = NULL;
	cmd.infile = av[1];
	cmd.outfile = av[ac - 1];
	cmd.len = ac - 3;
	cmd.mid_fd = -1;
	return (cmd);
}

void	ft_exec(t_cmd *cmd, char *file, char **commande)
{
	execve(file, commande, cmd->env);
	perror("execve failure");
	free(file);
	free_tab(commande);
	exit(EXIT_FAILURE);
}

void	parent_process(t_cmd *cmd)
{
	close(cmd->fd[1]);
	close(cmd->mid_fd);
	cmd->mid_fd = cmd->fd[0];
	cmd->fd[1] = -1;
	cmd->fd[0] = -1;
}
