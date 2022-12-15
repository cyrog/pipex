/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:34:17 by cgross            #+#    #+#             */
/*   Updated: 2022/12/15 14:23:18 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main()
{
	int id;
	int	n;

	id = fork();		//creates an other process, returns an int and child process always 0.
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(NULL);
	int	i = n;
	while (i < n + 5)
	{
		printf("%d ", i++);
		//fflush(stdout);
	}
	printf("\n");
	printf("hello world id : %d\n", id);
}
