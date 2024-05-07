/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:36:37 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/07 13:39:01 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

void	parent_process(char **argv, char **envp, int *fd);
void	child_process(char **argv, char **envp, int *fd);
void	exec(char *av, char *envp);
char	**get_cmds(char *cmd, char **path);
char	*find_path(char **envp);
void	print_error(char *msg);

#endif
