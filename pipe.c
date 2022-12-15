/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:24:22 by cgross            #+#    #+#             */
/*   Updated: 2022/12/15 14:39:30 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main()
{
	int fd[2];
	//fd[0] - read
	//fd[1] - write
	if (pipe(fd) == -1)
	{
		printf("error with pipe opening\n");
		return (1);
	}
	int id = fork();
	if (id == 0)	//child process (cause id = 0)
	{
		close(fd[0]);
		int x;
		printf("input number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else			//parent process (cause id != 0)
	{
		close (fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("got from child process %d\n", y);
	}
	return (0);
}
