/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:49:45 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/15 16:40:45 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	invalid_envp_path(char **argv)
{
	if (!access(argv[1], F_OK))
	{
		if (access(argv[2], X_OK))
			ft_printf("Error: No such file or director %s\n", argv[2]);
		if (access(argv[3], X_OK))
			ft_printf("Error: No such file or director %s\n", argv[3]);
	}
	else
	{
		ft_printf("Error: %s: No such file or directory\n", argv[1]);
		if (access(argv[3], X_OK))
		{
			ft_printf("Error: No such file or director %s\n", argv[3]);
			exit(EXIT_FAILURE);
		}
		if (access(argv[2], X_OK))
			ft_printf("Error: No such file or director %s\n", argv[2]);
	}
	exit(EXIT_FAILURE);
}

void	check_first_command(char **argv, char **envp, char **arr1)
{
	char	*result;

	result = get_executable(arr1[0], find_path(envp));
	if (check_full_command(argv[2]) == -4 && ft_counter(argv[2], ' ') > 1)
		check_inverted_commas(argv[2]);
	else if (!result)
		ft_printf("zsh: command not found: %s\n", arr1[0]);
	free(result);
}

void	write_stderror(char *str1, char *str2, char **arr1)
{
	if (str1)
		write(STDERR_FILENO, "First argument : Permission denied \n", 36);
	if (str2)
		write(STDERR_FILENO, "last argument : Permission denied \n", 35);
	if (arr1)
		remove_string(arr1);
}

int	check_permission(char **argv, char **envp, char **arr1, int n)
{
	int	fd ;
	int	fd1;

	fd = open(argv[1], O_RDWR);
	fd1 = open(argv[4], O_CREAT | O_WRONLY);
	if (fd == -1 && fd1 == -1)
	{
		write_stderror(argv[1], argv[4], arr1);
		exit(1);
	}
	if (fd == -1 && n == 1)
	{
		write_stderror(argv[1], NULL, arr1);
		return (0);
	}
	if (fd1 == -1 && arr1 != NULL)
	{
		write(STDERR_FILENO, "last argument : Permission denied \n", 35);
		check_first_command(argv, envp, arr1);
		remove_string(arr1);
		exit(0);
	}
	remove_string(arr1);
	return (1);
}
