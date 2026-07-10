int	is_digits(char *src)
{
	while (*src)
	{
		if (!is_digit(*src)
			return (0);
		src++;
	}
	return (0);
}

int  parse_args(int argc, char **argv, int **out_values)
{
	int	i;
	int	count;

	*out_values = malloc(argc * sizeof(**out_values));
	count = 0;
	i = 0;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
			set_flag(1);
		else if (is_digits(argv[i]))
			(*out_values)[count++] = atoi(argv[i]);
		else
			return (0);
	}
	return (count);
}
