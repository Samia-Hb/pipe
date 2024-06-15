/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:20:36 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/15 16:40:41 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_protect(char *command_path, char **new_arr)
{
	perror("execve");
	free(command_path);
	remove_string(new_arr);
	exit(1);
}

void	waaaaa(int *count, char **arr1, char **arr2)
{
	*count = 0;
	remove_string(arr1);
	remove_string(arr2);
	return ;
}

void	clear(char **arr1, char **arr2, char *result1, char *result2)
{
	remove_string(arr1);
	remove_string(arr2);
	free(result1);
	free(result2);
}

void	check_files_lenght(char **argv)
{
	if ((!ft_strlen(argv[1]) || !ft_counter(argv[1], ' '))
		&& (!ft_strlen(argv[4]) || !ft_counter(argv[4], ' ')))
	{
		write(STDERR_FILENO, "zsh: no such file or directory\n", 32);
		write(STDERR_FILENO, "zsh: no such file or directory\n", 32);
		exit(1);
	}
	if (!ft_strlen(argv[1]) || !ft_counter(argv[1], ' '))
	{
		write(STDERR_FILENO, "zsh: no such file or directory\n", 32);
		exit(1);
	}
	if (!ft_strlen(argv[4]) || !ft_counter(argv[4], ' '))
	{
		write(STDERR_FILENO, "zsh: no such file or directory\n", 32);
		exit(1);
	}
}
