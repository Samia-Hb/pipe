/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:29:39 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/15 16:39:46 by shebaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**empty_case(char **arr)
{
	if (!arr[0])
	{
		free(arr);
		arr = malloc(2 * sizeof(char *));
		arr[0] = ft_strdup(" ");
		arr[1] = NULL;
	}
	return (arr);
}

void	first_part(char **argv, char **arr2, int *count, char **envp)
{
	char	*result;
	char	*trimmed;

	ft_printf("zsh: no such file or directory: %s\n", argv[1]);
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
	*count = 0;
}

void	second_part(char **argv, char **envp, int *count)
{
	char	*result;
	char	**arr1;
	char	**arr2;

	arr1 = ft_split(argv[2], ' ');
	arr2 = ft_split(argv[3], ' ');
	arr1 = empty_case(arr1);
	arr2 = empty_case(arr2);
	result = get_executable(arr1[0], find_path(envp));
	if (check_full_command(argv[2]) == -4 && ft_counter(argv[2], ' ') > 1)
		check_inverted_commas(argv[2]);
	else if (!result)
		ft_printf("zsh: command not found: %s\n", arr1[0]);
	free(result);
	result = get_executable(arr2[0], find_path(envp));
	if (check_full_command(argv[3]) == -4 && ft_counter(argv[3], ' ') > 1)
		check_inverted_commas(argv[3]);
	else if (!result)
		ft_printf("zsh: command not found: %s\n", arr2[0]);
	if (result)
		free(result);
	waaaaa(count, arr1, arr2);
}

int	check_param(char **argv, char **envp)
{
	int		count;
	char	*result1;
	char	*result2;
	char	**arr1;
	char	**arr2;

	count = 1;
	arr1 = ft_split(argv[2], ' ');
	arr2 = ft_split(argv[3], ' ');
	arr1 = empty_case(arr1);
	arr2 = empty_case(arr2);
	result1 = get_executable(arr1[0], find_path(envp));
	result2 = get_executable(arr2[0], find_path(envp));
	if (access(argv[1], F_OK) != 0)
		first_part(argv, arr2, &count, envp);
	else if (!result1 || !result2)
		second_part(argv, envp, &count);
	if (!access(argv[1], F_OK))
	{
		if (!check_permission(argv, envp, NULL, 1))
			count = 0;
	}
	clear(arr1, arr2, result1, result2);
	return (count);
}

int	main(int argc, char **argv, char **envp)
{
	char	**arr1;

	if (!envp)
		return (0);
	if (argc == 5)
	{
		check_files_lenght(argv);
		arr1 = ft_split(argv[2], ' ');
		arr1 = empty_case(arr1);
		if (!find_path(envp))
			invalid_envp_path(argv);
		check_permission(argv, envp, arr1, 0);
		if (!check_param(argv, envp))
			return (0);
		execute_commands(argv, envp);
	}
	else
		ft_printf("Required : <infile> <cmd1> <cmd2> <outfile>\n");
	return (0);
}
