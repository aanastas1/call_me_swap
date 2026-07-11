//#include "push_swap.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

/*
	stack_* означает: функция работает с нашим стеком.
*/

typedef struct s_node
{
    int             value;      // 42
    int             rank;       // позиция числа в отсортированном массиве
    struct s_node   *next;      // указатель на следующий элемент
}   t_node;

typedef struct s_stack
{
    t_node          *top;       // первый элемент стека
    t_node          *bottom;    // последний элемент стека
    int             size;       // сколько элементов в стеке
}   t_stack;

void	stack_init(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

/*
	Похоже на ft_lstnew(), но это наш node:
	value - исходное число
	rank  - его индекс после сортировки
*/
t_node	*stack_create_node(int value, int rank)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->rank = rank;
	new->next = NULL;
	return (new);
}

/*
	Добавляет готовый node в начало стека
*/
void	stack_push_front(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->next = stack->top;
	stack->top = node;
	if (stack->size == 0)
		stack->bottom = node;
	stack->size++;
}

/*
	testy
*/
void	stack_print(const t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	printf("stack a, top -> ");
	while (current)
	{
		printf("[%d|rank:%d] ", current->value, current->rank);
		current = current->next;
        printf("\n");
	}
	printf("<- bottom\n");
}

void	stack_clear(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->bottom = NULL;
	stack->size = 0;
}

int	main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_init(&stack_a);
	stack_init(&stack_b);
	stack_push_front(&stack_a, stack_create_node(10, 0));
	stack_push_front(&stack_a, stack_create_node(42, 2));
	stack_push_front(&stack_a, stack_create_node(21, 1));
	stack_print(&stack_a);
    printf("\n");
	stack_clear(&stack_a);
    printf("\n");
	stack_clear(&stack_b);
    printf("\n");
	return (0);
}