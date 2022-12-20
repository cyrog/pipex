/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:33:01 by cgross            #+#    #+#             */
/*   Updated: 2022/12/20 15:17:41 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
}			t_pip;

void	error(char *str);
void	noexec(char *str);

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(int fd, char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);

char	**ft_free_split(char **dst, int *char_nbr);
char	**ft_split(const char *s, char c);

char	**get_all_path(char **envp);
char	*get_right_path(char **envp, char *cmd);

#endif
