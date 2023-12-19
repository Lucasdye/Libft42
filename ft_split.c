/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:57:23 by lbouguet          #+#    #+#             */
/*   Updated: 2023/01/02 15:52:11 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_clean(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

unsigned int	*ft_count_lens(const char *str, const char sep, unsigned int n)
{
	unsigned int	*lens;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	lens = (unsigned int *)malloc(n * sizeof(unsigned int));
	while (str[i])
	{
		if (str[i] != sep && str[i])
		{
			k = 1;
			while (str[i] != sep && str[i])
			{
				lens[j] = k++;
				i++;
			}
			j++;
		}
		if (!str[i])
			break ;
		i++;
	}
	return (lens);
}

unsigned int	ft_count_words(const char *str, const char sep)
{
	unsigned int	i;
	unsigned int	nb_words;

	nb_words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep && str[i])
		{	
			nb_words++;
			while (str[i] != sep && str[i])
				i++;
		}
		if (!str[i])
			break ;
		i++;
	}
	return (nb_words);
}

char	**ft_sort_tab(const	char *str, char **tab_str, char sep, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (k < n && str[i])
	{
		j = 0;
		while (str[i] == sep && str[i])
			i++;
		while (str[i] != sep && str[i])
		{	
			tab_str[k][j] = str[i];
			i++;
			j++;
		}
		tab_str[k][j] = '\0';
		k++;
	}
	return (tab_str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	*lens;
	unsigned int	nbw;
	char			**tab;

	if (!s)
		return (NULL);
	i = 0;
	nbw = ft_count_words(s, c);
	lens = ft_count_lens(s, c, nbw);
	tab = (char **)malloc(sizeof(char *) * (nbw + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nbw)
	{
		tab[i] = (char *)malloc((lens[i] + 1) * sizeof(char));
		if (!tab[i])
			ft_clean(tab);
		i++;
	}
	tab[i] = NULL;
	free(lens);
	tab = ft_sort_tab(s, tab, c, nbw);
	return (tab);
}
