/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:45:36 by chukim            #+#    #+#             */
/*   Updated: 2022/07/23 14:25:54 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_envp(char *envp[])
{
	char	*path;

	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == NULL)
		print_error("PATH error", 127);
	path = *envp + 5;
	return (ft_split(path, ':'));
}

char	*get_cmd_argv(char *path[], char *cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	path_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
}

void	fd_processing(int closed, int std_in, int std_out)
{
	close(closed);
	if (dup2(std_in, STDIN_FILENO) == -1)
		print_error("dup2 fail", 1);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		print_error("dup2 fail", 1);
	close(std_in);
	close(std_out);
}

int	arg_parse(t_arg *arg, char *argv[], char *envp[])
{
	int	result;

	result = 1;
	arg->infile = open(argv[1], O_RDONLY);
	if (arg->infile == -1)
		perror("infile error");
	arg->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile == -1)
		print_error("outfile error", 1);
	arg->path = get_envp(envp);
	arg->cmd_arg1 = ft_split(argv[2], ' ');
	arg->cmd_arg2 = ft_split(argv[3], ' ');
	arg->cmd1 = get_cmd_argv(arg->path, arg->cmd_arg1[0]);
	arg->cmd2 = get_cmd_argv(arg->path, arg->cmd_arg2[0]);
	if (arg->cmd1 == NULL || arg->cmd2 == NULL)
	{
		result = 127;
		perror("command not found");
	}
	return (result);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;
	int		result;

	if (argc != 5)
		print_error("argument error", 1);
	result = arg_parse(&arg, argv, envp);
	if (pipe(arg.pipe_fds) < 0)
		print_error("pipe error", 1);
	arg.pid = fork();
	if (arg.pid == -1)
		print_error("fork error", 1);
	else if (arg.pid == 0)
	{
		fd_processing(arg.pipe_fds[0], arg.infile, arg.pipe_fds[1]);
		if (execve(arg.cmd1, arg.cmd_arg1, envp) == -1)
			print_error("execve error", result);
	}
	else
	{
		fd_processing(arg.pipe_fds[1], arg.pipe_fds[0], arg.outfile);
		waitpid(arg.pid, NULL, WNOHANG);
		if (execve(arg.cmd2, arg.cmd_arg2, envp) == -1)
			print_error("execve error", result);
	}
	return (0);
}
