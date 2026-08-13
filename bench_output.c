/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:15:00 by anakloch          #+#    #+#             */
/*   Updated: 2026/08/13 15:13:20 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Writes a null-terminated benchmark string to standard error. */
void	bench_putstr(const char *text)
{
	ft_putstr_fd(text, STDERR_FILENO);
}

/* Writes a non-negative benchmark number to standard error. */
void	bench_putnbr(int number)
{
	ft_putnbr_fd(number, STDERR_FILENO);
}

/* Writes a disorder ratio as a percentage with exactly two decimals. */
void	bench_put_percent(double value)
{
	int	scaled;
	int	decimals;

	scaled = (int)(value * 10000.0 + 0.5);
	decimals = scaled % 100;
	bench_putnbr(scaled / 100);
	bench_putstr(".");
	if (decimals < 10)
		bench_putstr("0");
	bench_putnbr(decimals);
	bench_putstr("%\n");
}
