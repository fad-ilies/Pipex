/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:26:01 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/06 01:17:54 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char	**env;
	char	**av;
	char	*pathname;
	char	*infile;
	char	*outfile;
	pid_t	*pid;
	int		len;
	int		fd[2];
	int		mid_fd;
}			t_cmd;

char		*ft_strjoin2(char const *s1, char const *s2);
char		**path_check(t_cmd *cmd);
char		*cmd_check(t_cmd *cmd, char *s);
void		second_child(t_cmd *cmd);
void		first_child(t_cmd *cmd);
void		free_tab(char **str);
void		parse_cmd(t_cmd *cmd, char *s);
void		child1_if(t_cmd *cmd);
void		child2_of(t_cmd *cmd);
void		ft_exec(t_cmd *cmd, char *file, char **commande);
void		ft_error(t_cmd *cmd, int i);
void		ft_error2(t_cmd *cmd, char **commande);
void		ft_error3(char *file, char **commande);
void		child_fail(t_cmd *cmd, pid_t child, char **commande);
void		parent_process(t_cmd *cmd);
t_cmd		cmd_init(int ac, char **av, char **env);

#endif
