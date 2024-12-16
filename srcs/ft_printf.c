/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:53:42 by atrujill          #+#    #+#             */
/*   Updated: 2022/06/27 10:22:12 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_str(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_print_number(int nbr)
{
	char	*aux;
	int		len;

	aux = ft_itoa(nbr);
	ft_putstr_fd(aux, 1);
	len = ft_strlen(aux);
	free(aux);
	return (len);
}

int	ft_printf_mode(char mode, va_list args)
{
	int	len;

	len = 1;
	if (mode == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (mode == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (mode == 'p')
		len = ft_print_ptr(va_arg(args, unsigned long long));
	else if (mode == 'd' || mode == 'i')
		len = ft_print_number(va_arg(args, int));
	else if (mode == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (mode == 'x' || mode == 'X')
		len = ft_print_hexadecimal(va_arg(args, unsigned int), mode);
	else
		ft_putchar_fd(mode, 1);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_printf_mode(str[i], args);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
