#include "push_swap.h"
#include <unistd.h>

static int	fill_stack_a(t_arr *a, int *values, int count)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < count)
	{
		rank = 0;
		j = 0;
		while (j < count)
		{
			if (i != j && values[i] == values[j])
				return (0);
			if (values[j] < values[i])
				rank++;
			j++;
		}
		a->elements[count - 1 - i] = (t_element){values[i], rank};
		i++;
	}
	return (1);
}

static int	init_stacks(t_context *context, int *values, int count)
{
	context->a.elements = malloc(sizeof(t_element) * count);
	context->b.elements = malloc(sizeof(t_element) * count);
	if (!context->a.elements || !context->b.elements)
	{
		free(context->a.elements);
		free(context->b.elements);
		return (0);
	}
	context->a = (t_arr){context->a.elements, 0, count, count};
	context->b = (t_arr){context->b.elements, 0, 0, count};
	if (!fill_stack_a(&context->a, values, count))
	{
		free(context->a.elements);
		free(context->b.elements);
		return (0);
	}
	return (1);
}

static int	print_error(int *values)
{
	free(values);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	context;
	int			*values;
	int			count;

	if (argc == 1)
		return (0);
	memset(&context, 0, sizeof(context));
	context.strategy = NONE;
	values = NULL;
	count = parse_args(argc, argv, &values, &context);
	if (count <= 0)
		return (print_error(values));
	if (context.strategy == NONE)
		context.strategy = ADAPTIVE;
	if (!init_stacks(&context, values, count))
		return (print_error(values));
	free(values);
	/* Select and run the sorting strategy here. */
	free(context.a.elements);
	free(context.b.elements);
	return (0);
}
