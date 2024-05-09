/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:00:01 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/09 18:24:21 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char **path, char *cmd);

char	*get_path(char *cmd, char **envp)
{
	char	*final;
	int		idx;
	char	**path_arr;

	idx = 0;
	while (ft_strnstr(envp[idx], "PATH", 4) == 0)
		idx++;
	path_arr = ft_split(envp[idx] + 5, ':');
	final = path_finder(path_arr, cmd);
	idx = 0;
	while (path_arr[idx++])
		free(path_arr[idx]);
	free(path_arr);
	return (final);
}

char	*path_finder(char **path, char *cmd)
{
	
	char	*extract;
	char	*ans;
	int		idx;

	idx = 0;
	while (path[idx])
	{
		extract = ft_strjoin(path[idx], "/");
		ans = ft_strjoin(extract, cmd);
		free(extract);
		if (access(ans, X_OK) == 0)
			break ;
		free(ans);
		idx++;
	}
	return (ans);
}

void	print_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
