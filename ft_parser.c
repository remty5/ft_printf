/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:02:38 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/21 21:23:16 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS "-+ #0"
#define SPECS "diuoxXcsp%"

int	ft_next_spec(const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	return (i);
}

static int	ft_is_in(char c, char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static void	ft_handle_flag(char flag, t_flags *flags)
{
	if (flag == '-')
	{
		flags->leftjust = true;
		flags->zero = false;
	}
	else if (flag == '+')
	{
		flags->sign = true;
		flags->space = false;
	}
	else if (flag == ' ' && !flags->sign)
		flags->space = true;
	else if (flag == '#')
		flags->prefix = true;
	else if (flag == '0' && !flags->leftjust)
		flags->zero = true;
}

static int	ft_parse_nbr(const char *format, int *n, va_list args)
{
	int	i;

	if (*format == '*')
	{
		*n = va_arg(args, int);
		return (1);
	}
	i = 0;
	while ('0' <= format[i] && format[i] <= '9')
	{
		*n *= 10;
		*n += format[i] - '0';
		i++;
	}
	return (i);
}

int	ft_parse_spec(const char *format, va_list args, t_flags *flags)
{
	int	i;

	if (!*format)
		return (0);
	i = 1;
	while (ft_is_in(format[i], FLAGS))
		ft_handle_flag(format[i++], flags);
	i += ft_parse_nbr(format + i, &flags->width, args);
	if (format[i] == '.' && i++)
		i += ft_parse_nbr(format + i, &flags->precision, args);
	else
		flags->precision = -1;
	if (flags->zero && flags->width && flags->precision > 0)
		flags->zero = false;
	if (ft_is_in(format[i], SPECS))
		flags->spec = format[i++];
	return (i);
}
