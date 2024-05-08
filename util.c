/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:00:01 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/08 13:45:55 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**path_arr;
	char	*final;
	char	*extract;
	int		idx;

	idx = 0;
	while (ft_strnstr(envp[idx], "PATH", 4) == 0)
		idx++;
	path_arr = ft_split(envp[idx] + 5, ':');
	idx = 0;
	while (path_arr[idx++])
	{
		extract = ft_strjoin(path_arr[idx], "/");
		final = ft_strjoin(extract, cmd);
		free(extract);
		if (access(final, F_OK) == 0)
			break ;
		free(final);
	}
	idx = 0;
	while (path_arr[idx++])
		free(path_arr[idx]);
	free(path_arr);
	return (final);
}

void	print_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
