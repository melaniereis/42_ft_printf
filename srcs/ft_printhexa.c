/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:59:38 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 12:59:41 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_printhexa(unsigned int num, int *len, char s)
{
	char	string[25];
	char	*base;
	int		index;
	long	n;

	n = num;
	if (s == 'x')
		base = "0123456789abcdef";
	else if (s == 'X')
		base = "0123456789ABCDEF";
	index = 0;
	if (n == 0)
	{
		ft_printchar('0', len);
		return ;
	}
	while (n != 0)
	{
		string[index] = base[n % 16];
		n = n / 16;
		index++;
	}
	while (index--)
		ft_printchar(string[index], len);
}
