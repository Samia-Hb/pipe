/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:16:09 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/13 23:52:42 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_cmds(char **arr) // done
{
	int		i;
	char	cmp;

	i = 0;
	cmp = 39;
	while (arr[i] != NULL)
	{
		if (arr[i][0] == cmp)
			arr[i] = ft_strtrim(arr[i], "'");
		i++;
	}
}

char	*find_path(char **envp) // work
{
	int	i;

	if (!envp)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	check_command(char *cmd) // work
{
	char	**arr;

	arr = ft_split(cmd, ' ');
	if (access(arr[0], X_OK) == 0)
	{
		remove_string(arr);
		return (1);
	}
	remove_string(arr);
	return (0);
}

char	*find_command_path(char **dir, char *command) // work
{
	char	*full_path;
	int		i;

	i = 0;
	while (dir[i])
	{
		full_path = malloc(ft_strlen(dir[i]) + ft_strlen(command) + 2);
		if (!full_path)
		{
			perror("malloc");
			remove_string(dir);
			exit(1);
		}
		ft_strcpy(full_path, dir[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			remove_string(dir);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_executable(char *command, char *path) // work
{
	char	*command_path;
	char	**dir;
	char	**arr;

	arr = ft_split(command, ' ');
	if (!ft_counter(command, ' ') || !ft_strlen(command))
	{
		remove_string(arr);
		return (ft_strdup(" "));
	}
	if (access(arr[0], X_OK) == 0)
	{
		command_path = ft_strdup(arr[0]);
		remove_string(arr);
		return (command_path);
	}
	dir = ft_split(path, ':');
	command_path = find_command_path(dir, command);
	if (!command_path)
		remove_string(dir);
	remove_string(arr);
	return (command_path);
}
