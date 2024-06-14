/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:49:45 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/14 15:55:31 by shebaz           ###   ########.fr       */
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
