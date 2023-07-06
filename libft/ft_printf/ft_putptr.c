/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:54:17 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/07 10:32:05 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	size_t	tmp;
	int		count;

	tmp = (size_t) ptr;
	count = 2;
	write(1, "0x", 2);
	count += ft_unsigned_base(tmp, "0123456789abcdef");
	return (count);
}
