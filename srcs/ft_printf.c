/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:48:51 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 10:49:40 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./ft_printf.h"

static void	ft_printfcheck (char s, va_list *args, in *len, int *i)
{
	if (s == 'c')
		ft_printchar(var_arg(*args, char), len);
	else if (s == 's')
		ft_printstring(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_printpointer(va_arg(*args, void *), len);
	else if (s == 'd' || s == 'i')
		ft_printnum(va_arg(*args, int), len);
	else if (s == 'u')
		ft_printunsigned(va_arg(*args, size_t), len);	
	else if (s == 'x')
		ft_printhexa_lower(va_arg(*args, unsigned int), len);
	else if (s == 'X')
		ft_printhexa_upper(va_arg(*args, unsigned int), len);
	else if (s == '%')
		ft_printchar('%', len);
	else
		(*i)--;

}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int	i;
	int	lenght;

	i= 0;
	lenght = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printcheck(string[i], &args, &length);
		}
	}
	va_end(args);
	return (length);
}
