/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:54 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/20 16:21:24 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define CHARS "0123456789abcdef"

static void	ft_nbr_prefix(char *b, long n, t_flags *flags)
{
	int	i;

	i = 0;
	if (n < 0)
		b[i++] = '-';
	else if (flags->sign)
		b[i++] = '+';
	if (!i && flags->space)
		b[i++] = ' ';
	if (n != 0 && flags->prefix)
	{
		b[i++] = '0';
		if (flags->spec != 'o')
			b[i++] = flags->spec;
	}
}

int	ft_putnbr_base(long n, char base, t_flags *flags)
{
	char	b[101];
	int		i;
	int		j;

	ft_bzero(b, 101);
	ft_nbr_prefix(b, n, flags);
	i = 100;
	while (n != 0)
	{
		b[i--] = CHARS[n % base * ((n > 0) - (n < 0))];
		n /= base;
	}
	if (i == 100 && flags->precision != 0)
		b[100] = '0';
	i = 3;
	j = 0;
	while (i < 101)
		j += !!b[i];
	ft_memset(b + 3, '0', j);
	i = 0;
	j = 0;
	while (i < 101)
		if (b[i++])
			b[j++] = b[i - 1];
	return (ft_printstr(flags, b, j));
}

int	ft_spec_ptr(t_flags *flags, va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (ft_printstr(flags, "(nil)", 5));
	flags->prefix = true;
	return (ft_putnbr_base((long)ptr, 16, flags));
}
