/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:05:32 by cgross            #+#    #+#             */
/*   Updated: 2022/12/20 16:13:36 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_all_path(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			return (ft_split(&envp[0][5], ':'));
		envp++;
	}
	return (NULL);
}

char	*get_right_path(char **envp, char *cmd)
{
	int		i;
	char	**all_paths;
	char	*temp;
	char	*path;

	i = -1;
	all_paths = get_all_path(envp);
	while (all_paths && all_paths[++i])
	{
		temp = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		if (access(path, X_OK) != -1)
		{
			printf("ME HAS ACCESS\n");
			free(temp);
			ft_free_split(all_paths, NULL);
			return (path);
		}
		free(path);
		free(temp);
	}
	ft_free_split(all_paths, NULL);
	return (NULL);
}
