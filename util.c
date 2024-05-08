/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:00:01 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/08 11:41:56 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**path_arr;
	char	*final;
	char	*extract;
	int		idx;

	while (ft_strnstr(envp[idx], "PATH", 4) == 0)
		idx++;
}

void	print_error()
{
	perror("error");
}
