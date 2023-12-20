/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:31:58 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/20 16:28:04 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int (*const	g_spec[])(t_flags *flags, va_list args) = {\
	['d'] = &ft_spec_dec, \
	['i'] = &ft_spec_dec, \
	['u'] = &ft_spec_uns, \
	['o'] = &ft_spec_oct, \
	['x'] = &ft_spec_hex, \
	['X'] = &ft_spec_hex_upper, \
	['c'] = &ft_spec_char, \
	['s'] = &ft_spec_string, \
	['p'] = &ft_spec_ptr, \
};

int	ft_vprintf(const char *format, va_list args)
{
	t_flags	flags;
	int		ret;
	int		next;

	ft_bzero(&flags, sizeof(t_flags));
	next = ft_next_spec(format);
	if (next)
		return (ft_printstr(&flags, format, next)
			+ ft_vprintf(format + next, args));
	ret = 0;
	g_spec['s'](&flags, args);
	return (ft_vprintf(format, args));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vprintf(format, args);
	va_end(args);
	return (ret);
}
