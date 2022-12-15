/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:05:32 by cgross            #+#    #+#             */
/*   Updated: 2022/12/15 17:23:23 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_all_path(char **envp)
{
	while (*envp)
	{
		if (!strncmp(*envp, "PATH=", 5))
			return (ft_split(&envp[0][5], ':'));
		envp++;
	}
	return (NULL);
}

char	*get_right_path(char **envp, char *cmd)
{
	int	i;
	char	**all_path;
	char	*temp;
	char	*path;

	all_path = get_all_path(envp);
	while (all_paths && all_paths[i++])
	{
		temp = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		if (access(path, X_OK) != -1)
		{
			free(temp);
			//need free split here
			return (path);
		}
		free(path);
		free(temp);
	}
	//free split again here
	return (NULL);
}
