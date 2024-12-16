/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:25:55 by atrujill          #+#    #+#             */
/*   Updated: 2022/06/21 17:56:40 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_print_str(char *s);
int	ft_print_number(int nbr);
int	ft_printf_mode(char mode, va_list args);
int	ft_printf(char const *str, ...);
int	ft_unbrlen(unsigned int unbr);
int	ft_print_unsigned(unsigned int unbr);
int	ft_print_hexadecimal(unsigned long long nbr, char mode);
int	ft_print_ptr(unsigned long long nbr);

#endif
