/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:13:03 by cgross            #+#    #+#             */
/*   Updated: 2022/12/20 15:16:45 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	ft_putstr_fd(2, "error: ");
	if (errno)
		perror(str);
	else
		ft_putstr_fd(2, str);
	exit(EXIT_FAILURE);
}

void	noexec(char *name)
{
	ft_putstr_fd(STDERR_FILENO, "pipex: ");
	ft_putstr_fd(STDERR_FILENO, name);
	ft_putstr_fd(STDERR_FILENO, ": command not found\n");
	exit(127);
}
