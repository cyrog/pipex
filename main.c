/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:12:11 by cgross            #+#    #+#             */
/*   Updated: 2022/12/15 17:02:34 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, const char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	pipe(fd);
	pid1 = fork();
	if (argc != 5)
		perror("Usage: ./pipex infile 'cmd1' 'cmd2' outfile");
	if (pid1 == 0)		//child process 1 (ping)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "3", "42lausanne.ch", NULL);
	}
	pid2 = fork();
	if (pid2 == 0)		//child process 2 (grep)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "round-trip", NULL);
	}
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
