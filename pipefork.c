/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipefork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:53:01 by cgross            #+#    #+#             */
/*   Updated: 2022/12/15 15:06:40 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	int	arr[] = { 1, 2, 3, 4, 1, 2, 7, 7 };
	int	arrSize = sizeof(arr) / sizeof(int);
	int start;
	int end;
	int fd[2];
	if (pipe(fd) == -1)
		return (1);
	int id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = start + arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	int sum = 0;
	int i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}
	printf("calculated partial sum: %d\n", sum); 
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("total sum is %d\n", totalSum);
		wait(NULL);
	}
}
