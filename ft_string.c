/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:39:54 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/19 18:21:31 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(t_flags *flags, char *str, int len)
{
	int	ret;

	if (len < flags->width)
		ret = flags->width;
	else
		ret = len;
	while (flags->leftjust && len < flags->width--)
		write(1, &g_space, 1);
	write(1, str, len);
	while (len < flags->width--)
		write(1, &g_space, 1);
	return (ret);
}

int	ft_char(t_flags *flags, va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (ft_printstr(flags, &c, 1));
}

int	ft_string(t_flags *flags, va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	return (ft_printstr(flags, str, len));
}
