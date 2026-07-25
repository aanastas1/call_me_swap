#include "push_swap.h"

void strategy_simple(t_context *context)
{(void)context;}

void strategy_complex(t_context *context)
{(void)context;}
void strategy_adaptive(t_context *context)
{(void)context;}

int find_element(t_stack *arr, int nbr)
{
    int idx;
    int top;
    int delta;
    int res;
    int tmp;

    delta = arr->depth - 1;
    top = arr->depth - 1;
    idx = 0;
    while (top >= 0)
    {
        if (arr->top[idx].rank > nbr)
        {
            tmp = arr->top[idx].rank - nbr;
            if(tmp < delta)
            {
                delta = tmp;
                res = top;
            }
        }
        top--;
    }
    return (res);
}

void turk_alg(t_context *context)
{
    int target;
    int idx;
    int dist;

    pb(context);
    pb(context);
    idx = 0;
    target = context->b.top[idx].rank;
    idx = find_element(&context->a, target);
    dist = context->a.depth - 1 - idx;
    while (dist--)
        ra(context);
    pb(context);

}