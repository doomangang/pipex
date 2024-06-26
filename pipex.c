/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:35:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/05/09 13:57:08 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			print_error("Pipe Error");
		pid = fork();
		if (pid == -1)
			print_error("Fork Error");
		if (pid == 0)
			child_process(fd, argv, envp);
		waitpid(pid, &status, WNOHANG);
		parent_process(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		perror("Argument Error");
		exit(EXIT_FAILURE);
	}
	return (WEXITSTATUS(status));
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		print_error("Outfile Error");
	if (dup2(fd[0], STDIN_FILENO) < 0)
		print_error("dup2 Error");
	if (dup2(file_out, STDOUT_FILENO) < 0)
		print_error("dup2 Error");
	close(fd[1]);
	exec(argv[3], envp);
	close(file_out);
}

void	child_process(int *fd, char **argv, char **envp)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	if (file_in == -1)
		print_error("Infile Error");
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		print_error("dup2 Error");
	if (dup2(file_in, STDIN_FILENO) < 0)
		print_error("dup2 Error");
	close(fd[0]);
	exec(argv[2], envp);
	close(file_in);
}

void	exec(char *av, char **envp)
{
	char	*path;
	char	**cmd;
	int		idx;

	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		idx = 0;
		while (idx++)
			free(cmd[idx]);
		free(cmd);
		print_error("command not found");
	}
	if (execve(path, cmd, envp) == -1)
		print_error("execve Error");
}
