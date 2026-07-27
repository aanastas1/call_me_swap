int real_size(t_stack *stack)
{
    int count;
    t_node *n;

    if (!stack->top)
        return (0);

    count = 0;
    n = stack->top;

    do
    {
        count++;
        n = n->next;
    }
    while (n != stack->top);

    return (count);
}

void print_circle(t_stack *stack)
{
    t_node *n;

    if (!stack->top)
        return;

    n = stack->top;

    do
    {
        printf("%d ", n->rank);
        n = n->next;
    }
    while (n != stack->top);

    printf("\n");
}


void check_circle(t_stack *stack, char *name)
{
    t_node *n;
    int count;

    if (!stack->top)
        return;

    n = stack->top;
    count = 0;

    while (1)
    {
        if (!n)
        {
            printf("BROKEN %s: NULL pointer\n", name);
            exit(1);
        }

        count++;

        if (count > stack->depth)
        {
            printf("BROKEN %s: infinite loop\n", name);
            exit(1);
        }

        n = n->next;

        if (n == stack->top)
            break;
    }

    if (stack->top->prev == NULL)
    {
        printf("BROKEN %s: top->prev NULL\n", name);
        exit(1);
    }

    if (stack->top->prev->next != stack->top)
    {
        printf("BROKEN %s: last->next != top\n", name);
        exit(1);
    }
}
