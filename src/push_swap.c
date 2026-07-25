/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiko <aloiko@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:15:47 by aloiko            #+#    #+#             */
/*   Updated: 2026/07/25 18:13:31 by aloiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    strategy_selector(t_context *context)
{
    if (context->strategy == NONE)
        strategy_adaptive(context);
    if (context->strategy == SIMPLE)
        strategy_simple(context);
    if (context->strategy == MEDIUM)
        strategy_medium(context);
    if (context->strategy == COMPLEX)
        strategy_complex(context);
    if (context->strategy == ADAPTIVE)
        strategy_adaptive(context);
}
void  strategy_adaptive(t_context *context)
{
    //if (context->a.depth <= 50)
      //  strategy_simple(context);
    if (context->disorder < 0.05)
        strategy_simple(context);
    else if (context->disorder < 0.35)
        strategy_medium(context);
    else
        strategy_complex(context);
}

