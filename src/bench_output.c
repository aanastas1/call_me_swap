/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:15:00 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/25 11:31:27 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Writes a null-terminated benchmark string to standard error. */
void	bench_putstr(const char *text)
{
	int	length;

	if (!text)
		return;
	length = 0;
	while (text[length])
		length++;
	write(2, text, length);
}

/* Writes a non-negative benchmark number to standard error. */
void	bench_putnbr(int number)
{
	char	digit;

	if (number > 9)
		bench_putnbr(number / 10);
	digit = number % 10 + '0';
	write(2, &digit, 1);
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
