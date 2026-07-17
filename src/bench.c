#include "push_swap.h"

void	op_record(t_context *context, t_operation_type operation)
{
	if (operation < SA || operation >= OP_COUNT)
		return ;
	context->op_total++;
	context->op_counts[operation]++;
}

static const char	*operation_name(int operation)
{
	const char	*names[OP_COUNT];

	names[SA] = "sa";
	names[SB] = "sb";
	names[SS] = "ss";
	names[PA] = "pa";
	names[PB] = "pb";
	names[RA] = "ra";
	names[RB] = "rb";
	names[RR] = "rr";
	names[RRA] = "rra";
	names[RRB] = "rrb";
	names[RRR] = "rrr";
	return (names[operation]);
}

// mode (--bench)
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
		fprintf(stderr, "%s: %ld\n", operation_name(i),
			context->op_counts[i]);
		i++;
	}
}
