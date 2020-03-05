/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpoudre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:58:58 by wpoudre           #+#    #+#             */
/*   Updated: 2020/02/20 00:59:01 by wpoudre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char **s1, char **s2, int key)
{
	char	*res;

	if (s1 == NULL || s2 == NULL || key > 4 || key < 0)
		return (NULL);
	res = ft_strjoin(*s1, *s2);
	if ((key % 2) == 1)
	{
		free(*s1);
		*s1 = NULL;
		s1 = NULL;
	}
	if (key > 1)
	{
		free(*s2);
		*s2 = NULL;
		s2 = NULL;
	}
	return (res);
}
