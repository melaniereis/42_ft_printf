/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:59:21 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/04 12:59:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_printunsigned(unsigned int num, int *len)
{
	int	n;

	n = num;
	ft_putnbr_fd(n, 1);
}
