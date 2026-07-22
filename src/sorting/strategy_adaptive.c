/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakloch <anakloch@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:15:00 by anakloch          #+#    #+#             */
/*   Updated: 2026/07/22 11:36:30 by anakloch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Selects an internal strategy from the measured disorder. */
void	strategy_adaptive(t_context *context)
{
	if (context->disorder < 0.2)
		strategy_simple(context);
	else if (context->disorder < 0.5)
		strategy_medium(context);
	else
		strategy_complex(context);
	context->strategy_name = "Adaptive";
}
