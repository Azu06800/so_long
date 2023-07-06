/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:45:38 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/07 10:32:05 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_in_base2(char c, char *base)
{
	while (*base)
		if (c == *base++)
			return (1);
	return (0);
}

void	ft_print2(size_t n, char *base, unsigned int size, int *count)
{
	if (n > size - 1)
	{
		ft_print2(n / size, base, size, count);
		n %= size;
	}
	ft_putchar(base[n]);
	*count += 1;
}

int	ft_unsigned_base(size_t nbr, char *base)
{
	int	size;
	int	count;

	count = 0;
	size = -1;
	while (base[++size])
		if (base[size] == '+' || base[size] == '-' || base[size] == ' '
			|| ft_in_base2(base[size], base + size + 1)
			|| (base[size] >= 9 && base[size] <= 13))
			return (0);
	if (size < 2)
		return (0);
	if (nbr < 0)
	{
		ft_putchar('-');
		count++;
		ft_print2(-nbr, base, size, &count);
	}
	else
		ft_print2(nbr, base, size, &count);
	return (count);
}
