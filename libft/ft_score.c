/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:43:09 by amasol            #+#    #+#             */
/*   Updated: 2017/11/27 16:43:16 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_score(char const *str, char c)
{
	int i;
	int shet;

	i = 0;
	shet = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			shet++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (shet);
}
