/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-19 10:21:26 by selango           #+#    #+#             */
/*   Updated: 2024-09-19 10:21:26 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

/*this function returns only the string without spaces*/
static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char sep)
{
	int		words_number;
	char	**array_strings;
	int		i;

	i = 0;
	words_number = count_words(str, sep);
	if (!words_number)
		exit(1);
	array_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (!array_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			array_strings[i] = malloc(sizeof(char));
			if (array_strings[i] == NULL)
				return (NULL);
			array_strings[i++][0] = '\0';
			continue ;
		}
		array_strings[i++] = get_next_word(str, sep);
	}
	array_strings[i] = NULL;
	return (array_strings);
}
