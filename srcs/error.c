/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:13:03 by cgross            #+#    #+#             */
/*   Updated: 2022/12/22 16:05:44 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	ft_putstr_fd("error: ", 2);
	if (errno)
		perror(str);
	else
		ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	noexec(char *name)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}
