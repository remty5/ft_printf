/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:54 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/19 18:35:40 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define CHARS "0123456789abcdef"

int	ft_putnbr_base(long n, char base, t_flags *flags)
{
	char	b[102];
	int		i;
	int		j;

	ft_bzero(b, 102);
	if (n < 0)
		b[0] = '-';
	i = 100;
	while (n != 0)
	{
		b[i--] = CHARS[n % base * ((n > 0) - (n < 0))];
		n /= base;
	}
	if (i == 100)
		b[100] = '0';
	i = 0;
	j = 0;
	while (i < 101)
		if (b[i++])
			b[j++] = b[i - 1];
	return (ft_printstr(flags, b, j));
}
