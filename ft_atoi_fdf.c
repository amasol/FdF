/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:34:51 by amasol            #+#    #+#             */
/*   Updated: 2018/10/20 14:34:52 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long int		ft_atoi_fdf(char *str, int *i)
{
	int					j;
	char				*s;
	unsigned long int	nom;
	int					negativ;

	s = (char *)str;
	nom = 0;
	negativ = 1;
	j = (*i);
	while (ft_isspace(s[j]))
		j++;
	if (s[j] == '-')
		negativ = -1;
	if (s[j] == '+' || s[j] == '-')
		j++;
	while (ft_isdigit(s[j]))
	{
		nom = nom * 10 + s[j] - 48;
		j++;
		if (nom >= 9223372036854775807 && negativ == 1)
			return (-1);
		else if (nom > 9223372036854775807 && negativ == -1)
			return (0);
	}
	nom *= negativ;
	(*i) = j;
	return (nom);
}
