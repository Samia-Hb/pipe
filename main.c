/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:29:39 by shebaz            #+#    #+#             */
/*   Updated: 2024/06/14 23:20:37 by shebaz           ###   ########.fr       */
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

void	first_part(char *infile, char **arr2, char *cmd2, char **envp)
{
	char	*result;
	char	*trimmed;

	ft_printf("zsh: no such file or directory: %s\n", infile);
	result = get_executable(arr2[0], find_path(envp));
	if (check_full_command(cmd2) == -4 && ft_counter(cmd2, ' ') > 1)
	{
		trimmed = ft_strtrim(cmd2, "'");
		ft_printf("zsh: command not found: %s\n", trimmed);
		free(trimmed);
	}
	else if (!result)
		ft_printf("zsh: command not found: %s\n", arr2[0]);
	if (result)
		free(result);
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
	if(!check_all(argv, arr2, envp))
		return (waaaaa(count, arr1, arr2));
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
	{
		first_part(argv[1], arr2, argv[3], envp);
		count = 0;
	}
	else if (!result1 || !result2 || !access(argv[1], F_OK))
		second_part(argv, envp, &count);
	remove_string(arr1);
	remove_string(arr2);
	free(result1);
	free(result2);
	return (count);
}

int	check_permission(char *infile, char *outfile, int n)
{
	int fd ;
	int fd1;
	
	fd = open(infile, O_RDWR);
	fd1 = open(outfile, O_CREAT| O_WRONLY);
	if (fd == -1 && fd1 == -1)
	{
		write(STDERR_FILENO, "First argument : Permission denied \n", 36);
		write(STDERR_FILENO, "last argument : Permission denied \n", 35);
		exit(1);
	}
	if (fd == -1 && n == 1)
	{
		write(STDERR_FILENO, "First argument : Permission denied \n", 36);
		return (0);
	}
	return (1);
}
int	main(int argc, char **argv, char **envp)
{
	if (!envp)
		return (0);
	if (argc == 5)
	{
		if (!find_path(envp))
			invalid_envp_path(argv);
		check_permission(argv[1], argv[4] , 0);
		if (!check_param(argv, envp))
			return (0);
		execute_commands(argv, envp);
	}
	else
		ft_printf("zsh: parse error near `\\n' \n");
	return (0);
}
