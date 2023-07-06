/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:29:06 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/04 19:08:08 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_in_base(char c, char *base)
{
	while (*base)
		if (c == *base++)
			return (1);
	return (0);
}

void	ft_print(unsigned int n, char *base, unsigned int size, int *count)
{
	if (n > size - 1)
	{
		ft_print(n / size, base, size, count);
		n %= size;
	}
	ft_putchar(base[n]);
	*count += 1;
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	count;

	count = 0;
	size = -1;
	while (base[++size])
		if (base[size] == '+' || base[size] == '-' || base[size] == ' '
			|| ft_in_base(base[size], base + size + 1)
			|| (base[size] >= 9 && base[size] <= 13))
			return (0);
	if (size < 2)
		return (0);
	if (nbr < 0)
	{
		ft_putchar('-');
		count++;
		ft_print(-nbr, base, size, &count);
	}
	else
		ft_print(nbr, base, size, &count);
	return (count);
}
