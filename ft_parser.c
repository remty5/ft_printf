/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:02:38 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/20 16:10:31 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_next_spec(const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	return (i);
}
