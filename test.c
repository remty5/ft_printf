/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:51:46 by rvandepu          #+#    #+#             */
/*   Updated: 2023/11/11 23:54:07 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf(void)
{
	ft_putstr_fd("test\n", 1);
}

int	main(void)
{
	ft_printf();
}