/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:06:39 by cgross            #+#    #+#             */
/*   Updated: 2022/11/02 14:18:45 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	string_count(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static char	*word(char const *s, char c, int start)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	j = start;
	len = 0;
	i = 0;
	while (s[start] != c)
	{
		start++;
		len++;
	}
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	while (s[j] != c && s[j])
		word[i++] = s[j++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		tab;
	int		i;

	split = malloc(sizeof(char *) * (string_count(s, c) + 1));
	if (!split || !s)
		return (0);
	tab = 0;
	i = 0;
	while (tab < string_count(s, c))
	{
		while (s[i] == c)
			i++;
		split[tab] = word(s, c, i);
		while (s[i] != c)
			i++;
		tab++;
	}
	split[tab] = 0;
	return (split);
}
