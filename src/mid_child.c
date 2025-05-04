/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:15:13 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/05 00:40:19 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    check_mid_fd(t_cmd *cmd)
{
    if (cmd->prev < 0 || cmd->next < 0)
    {
        ft_putstr_fd("Invalid fd\n", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
void        mid_child(t_cmd *cmd, char *mid_cmd)
{
    char *file;
    char **commande;

    check_mid_fd(cmd);
    commande = ft_split(mid_cmd, ' ');
    file = get_cmd(cmd, commande[0]);
    if (!commande || !commande[0] || !file)
    {
        free_tab(commande);
        if (file)
            free(file);
		exit(EXIT_FAILURE);
    }
    dup2(cmd->prev, STDIN_FILENO);
    close(cmd->prev);
    dup2(cmd->next, STDOUT_FILENO);
    close(cmd->next);
    execve(file, commande, cmd->env);
    ft_putstr_fd("Command not found\n", 2);
    free_tab(commande);
    free(file);
    exit(EXIT_FAILURE);
}
