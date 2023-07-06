/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:56:42 by nihamdan          #+#    #+#             */
/*   Updated: 2023/04/07 10:31:11 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_flag(char c)
{
	return (ft_strchr("cspdiuxX%", c) != 0);
}

int	ft_flag_list(char flag, va_list arg, int len)
{
	if (flag == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (flag == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (flag == 'p')
		len += ft_putptr(va_arg(arg, void *));
	else if (flag == 'd')
		len += ft_putnbr_base(va_arg(arg, int), "0123456789");
	else if (flag == 'i')
		len += ft_putnbr_base(va_arg(arg, int), "0123456789");
	else if (flag == 'u')
		len += ft_unsigned_base(va_arg(arg, unsigned int), "0123456789");
	else if (flag == 'x')
		len += ft_unsigned_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (flag == 'X')
		len += ft_unsigned_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (flag == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_arg(const char *s, va_list arg, int len)
{
	int	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (ft_is_flag(s[i + 1]))
			{
				i++;
				len = ft_flag_list(s[i], arg, len);
			}
			i++;
		}
		else
			len += ft_putchar(s[i++]);
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	arg;

	len = 0;
	if (!s)
		return (0);
	va_start(arg, s);
	len = ft_arg(s, arg, len);
	va_end(arg);
	return (len);
}
