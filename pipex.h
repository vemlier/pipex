/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:57:02 by chukim            #+#    #+#             */
/*   Updated: 2022/07/07 11:43:16 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**path;
	char	*cmd1;
	char	**cmd_arg1;
	char	*cmd2;
	char	**cmd_arg2;
	int		pipe_fds[2];
	pid_t	pid;
}	t_arg;

void	print_error(char *message, int error_code);
int		arg_parse(t_arg *arg, char *av[], char *envp[]);
char	**get_envp(char *envp[]);
char	*get_cmd_argv(char *path[], char *cmd);
void	fd_processing(int closed, int std_in, int std_out);
#endif