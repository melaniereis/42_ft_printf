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
	char	*base;
	int		index;

	if (s == 'x')
		base = "0123456789abcdef";
	else if (s == 'X')
		base = "0123456789ABCDEF";
	
	index = 0;
	if (num >= 16)
	{
		
		num = num / 16;
	}

}
