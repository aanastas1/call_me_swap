#include "push_swap.h"

static const char	*g_operation_names[OP_COUNT] = 
{
	"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
};

void	op_record(t_context *context, t_operation_type operation)
{
	if (operation < SA || operation >= OP_COUNT)
		return ;
	context->op_total++;
	context->op_counts[operation]++;
}

void	bench_print_and_counts(t_context *context, double disorder,
		const char *strategy_name, const char *complex_class)
{
	int	i;

	if (!context->bench_enabled)
		return ;
	fprintf(stderr, "disorder: %.2f%%\n", disorder * 100.0);
	fprintf(stderr, "strategy: %s (%s)\n", strategy_name, complex_class);
	fprintf(stderr, "operations: %ld\n", context->op_total);
	i = 0;
	while (i < OP_COUNT)
	{
		fprintf(stderr, "%s: %ld\n", g_operation_names[i],
			context->op_counts[i]);
		i++;
	}
}
