/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:51:46 by rvandepu          #+#    #+#             */
/*   Updated: 2023/12/19 18:30:53 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("'%c'\n", 't');
	printf("'%2c'\n", 't');
	printf("'%-2c'\n", 't');
	//ft_printf("Hello world! %d\n", 123);
}
