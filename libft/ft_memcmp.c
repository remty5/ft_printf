/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:02:14 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/18 17:32:25 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *) s1)[i] == ((unsigned char *) s2)[i])
		i++;
	if (i < n)
		return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
	else
		return (0);
}
