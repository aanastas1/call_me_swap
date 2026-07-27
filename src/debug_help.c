pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	print_stack_a_b(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	pa(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	ra(&context);
	pb(&context);
	print_stack_a_b(&context);

	rrr(&context);
	print_stack_a_b(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	pb(&context);
	print_stack_a_b(&context);
	rb(&context);
	print_stack_a_b(&context);
	rb(&context);
	print_stack_a_b(&context);
	rr(&context);
	print_stack_a_b(&context);
	ra(&context);
	print_stack_a_b(&context);
	rrr(&context);
	print_stack_a_b(&context);*/


	//turk_alg(&context);

	printf("Disorder: %.2f\n", context.disorder);
	


	printf("DEBUG:     depth.a = %d,                depth.b = %d\n", context.a.depth,  context.b.depth);
	printf("DEBUG:     operation_totaly = %d\n", context.op_total);
	//print_stack_a_b(&context); /* print stack after small functions */

	if (context.bench_enabled)
		bench_print_and_counts(&context);

	t_node *p = context.a.top;

	for (int i = 0; i < context.a.depth; i++)
	{
    	printf("%d -> ", p->rank);
   		p = p->next;
	}

	printf("BACK %d\n", p->rank);


	printf("BEFORE FREE A=%d B=%d TOTAL=%d\n",
    context.a.depth,
    context.b.depth,
    context.a.depth + context.b.depth);

	print_stack_a_b(&context);

	x = context.a.top;

	for (int i = 0; i < context.a.depth; i++)
	{
    	printf("%d -> ", x->rank);
    	x = x->next;
	}

	printf("END rank=%d\n", x->rank);
	printf("TOP rank=%d\n", context.a.top->rank)