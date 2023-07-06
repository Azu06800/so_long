/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:34:34 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/07 10:27:51 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str != NULL)
	{
		while (*str)
		{
			ft_putchar(*str);
			str++;
			count++;
		}
	}
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	return (count);
}
