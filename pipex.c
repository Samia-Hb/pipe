/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:35:00 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/14 22:48:35 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_empty_cmd1(char *infile)
{
	int	infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd == -1)
	{
		write(STDERR_FILENO, "First argument : Permission denied \n", 36);
		exit(0);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	return ;
}

void	execute_cmd1(int pipe_fd_0, int pipe_fd_1, char **argv, char **envp)
{
	int		infile_fd;
	char	**new_arr;
	char	*command_path;

	if (!ft_counter(argv[2], ' ') || !ft_strlen(argv[2]))
		return (execute_empty_cmd1(argv[1]));
	close(pipe_fd_0);
	dup2(pipe_fd_1, STDOUT_FILENO);
	close(pipe_fd_1);
	infile_fd = open(argv[1], O_RDONLY, 0777);
	if (infile_fd == -1)
		exit(0);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	new_arr = arr(argv[2]);
	command_path = get_executable(new_arr[0], find_path(envp));
	if (execve(command_path, new_arr, envp) == -1)
		exe_protect(command_path, new_arr);
	remove_string(new_arr);
}

void	execute_empty_cmd2(char *outfile, int pipe_fd_0)
{
	int		outfile_fd;
	char	*str;

	str = NULL;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC);
	if (outfile_fd == -1)
	{
		write(STDERR_FILENO, "last argument : Permission denied \n", 34);
		exit(0);
	}
	dup2(pipe_fd_0, STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(pipe_fd_0);
	close(outfile_fd);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		write(STDOUT_FILENO, str, ft_strlen(str));
		free(str);
	}
	return ;
}

void	execute_cmd2(int pipe_fd_0, int pipe_fd_1, char **argv, char **envp)
{
	int		outfile_fd;
	char	**new_arr;
	char	*command_path;

	close(pipe_fd_1);
	if (ft_counter(argv[3], ' ') == 0 || ft_strlen(argv[3]) == 0)
		return (execute_empty_cmd2(argv[4], pipe_fd_0));
	dup2(pipe_fd_0, STDIN_FILENO);
	close(pipe_fd_0);
	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (outfile_fd == -1)
		exit(0);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	new_arr = arr(argv[3]);
	command_path = get_executable(new_arr[0], find_path(envp));
	if (execve(command_path, new_arr, envp) == -1)
		exe_protect(command_path, new_arr);
	remove_string(new_arr);
}

void	norm(int pipe_fd_0, int pipe_fd_1, int pid1, int pid2)
{
	close(pipe_fd_0);
	close(pipe_fd_1);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
