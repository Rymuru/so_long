/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:45:40 by bcoenon           #+#    #+#             */
/*   Updated: 2022/11/10 18:46:24 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_sign(int n)
{
	if (n <= 0)
		return (2);
	return (1);
}

static int	ft_countmem(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_fill(char *mem, unsigned int n, int sign, int nb)
{
	int	i;

	i = sign + nb - 1;
	if (sign == 2)
	{
		if (n != 0)
			mem[0] = '-';
		else
			mem[0] = '0';
	}
	mem[i] = '\0';
	i--;
	while (n)
	{
		mem[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (mem);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		nb;
	char	*mem;

	sign = ft_sign(n);
	nb = ft_countmem(n);
	mem = (char *)malloc(sizeof(char) * (nb + sign));
	if (!mem)
		return (NULL);
	if (sign == 2)
		n = (unsigned int)(n * (-1));
	mem = ft_fill(mem, n, sign, nb);
	return (mem);
}
