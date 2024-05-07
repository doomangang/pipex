/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:35:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/07 14:31:01 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			print_error();
		pid = fork();
		if (pid == -1)
			print_error();
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		//error on command
	}
	return (0);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		print_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY, 0777);
	if (file_in == -1)
		print_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	exec(argv[2], envp);
}

void    exec(char *av, char **envp)
{
	
	execve();
}
