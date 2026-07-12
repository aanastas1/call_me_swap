/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:39:35 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/12 18:39:41 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int		*values;
	int		n;
	double	disorder;
	int		*ranks;
	t_context	context;

	if (argc < 2)
		return (0);

	values = NULL;
	n = parse_args(argc, argv, &values, &context);
	if (n <= 0 || !values)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}

	if (!validate_ints_and_no_dups(values, n))
		return (0);

	disorder = compute_disorder_values(values, n);
	ranks = compute_ranks(values, n);

	/* дальше: build stacks a/b, стратегия, операции */
	(void)disorder;
	(void)ranks;

	free(values);
	free(ranks);
	return (0);
}

