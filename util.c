/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:00:01 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/08 23:32:20 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char *path, char *cmd);

char	*get_path(char *cmd, char **envp)
{
	char	*final;
	int		idx;

	idx = 0;
	while (ft_strnstr(envp[idx], "PATH", 4) == 0)
		idx++;
	final = path_finder(envp[idx], cmd);
	return (final);
}

char	*path_finder(char *path, char *cmd)
{
	char	**path_arr;
	char	*extract;
	char	*ans;
	int		idx;

	path_arr = ft_split(path + 5, ':');
	idx = 0;
	while (path_arr[idx++])
	{
		extract = ft_strjoin(path_arr[idx], "/");
		ans = ft_strjoin(extract, cmd);
		free(extract);
		if (access(ans, X_OK) == 0)
			break ;
		free(ans);
	}
	idx = 0;
	while (path_arr[idx++])
		free(path_arr[idx]);
	free(path_arr);
	return (ans);
}

void	print_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
