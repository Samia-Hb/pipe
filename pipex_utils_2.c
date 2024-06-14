/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:49:45 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/14 23:20:41 by shebaz           ###   ########.fr       */
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

void	exe_protect(char *command_path, char **new_arr)
{
	perror("execve");
	free(command_path);
	remove_string(new_arr);
	exit(1);
}

void waaaaa(int *count, char **arr1, char **arr2)
{
	*count = 0;
	remove_string(arr1);
	remove_string(arr2);
	return ;
}

int check_all(char **argv,char **arr2, char **envp)
{
	char	*result;
	char	*trimmed;
	
	if (!check_permission(argv[1], argv[4], 1))
	{
		result = get_executable(arr2[0], find_path(envp));
		if (check_full_command(argv[3]) == -4 && ft_counter(argv[3], ' ') > 1)
		{
			trimmed = ft_strtrim(argv[3], "'");
			ft_printf("zsh: command not found: %s\n", trimmed);
			free(trimmed);
		}
		else if (!result)
			ft_printf("zsh: command not found: %s\n", arr2[0]);
		if (result)
			free(result);
		return (0);
	}
	return (1);
}
