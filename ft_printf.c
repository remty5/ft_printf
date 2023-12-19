/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:31:58 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/19 17:46:12 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int (*const	g_spec[])(t_flags *flags, va_list args) = {\
	['c'] = &ft_char, \
	['s'] = &ft_string, \
	['p'] = 0, \
	['d'] = 0, \
	['i'] = 0, \
	['u'] = 0, \
	['x'] = 0, \
	['X'] = 0
};

int	ft_vprintf(const char *format, va_list args)
{
	t_flags	flags;
	// TODO find next spec
	(void) format;
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
