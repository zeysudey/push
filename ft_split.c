/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:37:29 by zyilmaz           #+#    #+#             */
/*   Updated: 2024/10/27 18:33:38 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// Kaç kelime olduğunu hesaplar
static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

// Ana işlev: Split işlemini gerçekleştirir
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		start;
	if (!s)
		return (NULL);

	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);

	i = 0;
	j = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			result[j] = ft_substr(s, start, (s[i] == c) ? i - start : (i + 1) - start);
			if (!result[j])
				return (NULL); // Belleği serbest bırakmıyoruz, çağıran fonksiyon sorumlu olacak
			j++;
			start = -1;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}