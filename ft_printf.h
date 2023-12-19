/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:43 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/19 18:35:02 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	bool	leftjust;
	bool	sign;
	bool	space;
	bool	prefix;
	bool	zeropad;
	int		width;
	int		precision;
	bool	upper;
}	t_flags;

static const char	g_space = ' ';
static const char	g_zero = '0';

// ft_string.c
int	ft_printstr(t_flags *flags, char *str, int len);
int	ft_char(t_flags *flags, va_list args);
int	ft_string(t_flags *flags, va_list args);

// ft_print.c
int	ft_print(va_list args);

// ft_printf.c
int	ft_vprintf(const char *format, va_list args);
int	ft_printf(const char *format, ...);

#endif
