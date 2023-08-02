/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:54:58 by yoelansa          #+#    #+#             */
/*   Updated: 2023/08/02 16:39:41 by yoelansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (1);
	while (str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	_atoi(char *str)
{
	size_t	r;
	int		i;

	r = 0;
	i = 0;
	if (!str)
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		r = r * 10 + str[i] - 48;
		if (r > INT32_MAX)
			return (-1);
		i++;
	}
	return (r);
}

int	_valid_args(int ac, char **args)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		printf("invalid_number_of_args\n");
		return (1);
	}
	if (!args)
		return (1);
	i = 1;
	while (args[i])
	{
		if (ft_str_is_digit(args[i]) == 1)
		{
			printf("incorrect numbers\n");
			return (1);
		}
		else if (_atoi(args[i]) == -1 || !_atoi(args[i]))
		{
			printf("incorrect arguments\n");
			return (1);
		}
		i++;
	}
	return (0);
}
