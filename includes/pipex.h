/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifadhli <ifadhli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:26:01 by ifadhli           #+#    #+#             */
/*   Updated: 2025/04/30 00:28:13 by ifadhli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "libft.h"
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
}			t_cmd;

char		*ft_strjoin2(char const *s1, char const *s2);
char		**get_path(t_cmd *cmd);
char		*get_cmd(t_cmd *cmd);
void		create_child(t_cmd *cmd);
void		create_pipe(int fd[2]);
void		pipe_dad(void);

#endif
