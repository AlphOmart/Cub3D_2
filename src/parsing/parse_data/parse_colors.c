/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwubneh <mwubneh@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:59:14 by mwubneh           #+#    #+#             */
/*   Updated: 2024/01/30 16:24:56 by mwubneh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_split_size(char **temp);
static bool			only_digit(char *str);

void	free_split(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

/**
 * @brief "This function splits `to_get`, checks that it returns a
 *		string array of size 3, then applies the `atoi` function
 *		to each of the elements and stores them in an integer array."
 * @param colors[3]"An integer array where the elements of `to_get`
 *			will be parsed."
 * @param *to_get "The string that will be split, on which `atoi`
 *			will be applied, and then stored in `colors`."
 */
void	get_colors(int colors[3], char *to_get)
{
	char	**temp;
	size_t	i;

	i = 0;
	to_get = trim_end(to_get);
	if (!ft_isdigit(to_get[ft_strlen(to_get) - 1]))
		return (errno = 4, (void)NULL);
	while (to_get[i] && ft_isspace(to_get[i]))
		i++;
	temp = ft_split(&to_get[i], ',');
	if (get_split_size(temp) != 3)
		return (errno = 4, free_split(temp));
	i = 0;
	while (temp[i])
	{
		if (!only_digit(temp[i]))
			errno = 4;
		colors[i] = ft_atoi(temp[i]);
		i++;
	}
	free_split(temp);
}

static bool			only_digit(char *str)
{
	size_t	i;

	i = 0;

	while (str[i])
	{
		while(str[i] && ft_isspace(str[i]))
			i++;
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return true;
}

/**
 * @brief Calculate the size of a char ** variable passed as a parameter.
 * @param **temp Array of strings whose size needs to be calculated.
 * @return Returns the size of the string
 */
static size_t	get_split_size(char **temp)
{
	size_t	i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}