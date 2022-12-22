/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:33:01 by cgross            #+#    #+#             */
/*   Updated: 2022/12/22 16:38:34 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <errno.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pip
{
	const char	*path[2];
	char *const	*cmd[2];
	int			pid[2];
	int			file[2];
	int			pipe[2];
	int			exit;
}			t_pip;

void	error(char *str);
void	nofile(char *str);
void	noexec(char *str);
char	**ft_free_split(char **dst, int *char_nbr);

char	**get_all_path(char **envp);
char	*get_right_path(char **envp, char *cmd);

#endif
