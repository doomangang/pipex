/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:35:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/07 21:18:15 by jihyjeon         ###   ########.fr       */
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
			child_process(fd, argv, envp);
		waitpid(pid, NULL, WNOHANG);
		parent_process(fd, argv, envp);
	}
	else
		print_error();
	return (0);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		perror(" ");
	dup2(fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], envp);
}

void	child_process(int *fd, char **argv, char **envp)
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

void	exec(char *av, char **envp)
{
	char	*path;
	char	**cmd;
	int		idx;

	cmd = ft_split(av, ' ');
	path = find_path(*cmd, envp);
	if (!path)
	{
		idx = 0;
		while (idx++)
			free(cmd[idx]);
		free(cmd);
		print_error();
	}
	if (execve(path, cmd, envp) == -1)
		print_error();
}
