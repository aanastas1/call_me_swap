int main(int argc, char **argv)
{
	int		*values;
	int		n;
	double	disorder;
	int		*ranks;

	if (argc < 2)
		return (0);

	values = NULL;
	n = parse_args(argc, argv, &values);
	if (n <= 0 || !values)
		return (0);

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

