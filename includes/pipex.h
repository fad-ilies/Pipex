/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:26:01 by ifadhli           #+#    #+#             */
/*   Updated: 2025/05/01 23:53:40 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
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
}			t_cmd;

char		*ft_strjoin2(char const *s1, char const *s2);
char		**get_path(t_cmd *cmd);
char		*get_cmd(t_cmd *cmd, char *s);
void		second_child(t_cmd *cmd);
void		first_child(t_cmd *cmd);
void		free_tab(char **str);
void    parse_cmd(t_cmd *cmd, char *s);

#endif
