/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:06 by atrujill          #+#    #+#             */
/*   Updated: 2022/06/21 18:00:18 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_unbrlen(unsigned int unbr)
{
	int	i;

	i = 0;
	while (unbr != 0)
	{
		unbr = unbr / 10;
		i++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int unbr)
{
	char	*aux;
	int		len;

	if (unbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = ft_unbrlen(unbr);
	aux = ft_calloc(len + 1, sizeof(char));
	while (unbr != 0)
	{
		aux[len - 1] = (unbr % 10) + '0';
		unbr = unbr / 10;
		len--;
	}
	ft_putstr_fd(aux, 1);
	len = ft_strlen(aux);
	free(aux);
	return (len);
}

int	ft_print_hexadecimal(unsigned long long nbr, char mode)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_print_hexadecimal(nbr / 16, mode);
		len += ft_print_hexadecimal(nbr % 16, mode);
	}
	else
	{
		if (mode == 'x')
			ft_putchar_fd("0123456789abcdef"[nbr], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[nbr], 1);
		len++;
	}
	return (len);
}

int	ft_print_ptr(unsigned long long nbr)
{
	int	len;

	ft_putstr_fd("0x", 1);
	len = 2;
	len += ft_print_hexadecimal(nbr, 'x');
	return (len);
}
