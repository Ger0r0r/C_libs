#ifndef STACK_LIBRARY
#define STACK_LIBRARY

#include <stdio.h>
#include <stdlib.h>

//5859552C50494452
//2C54454C4B412121

typedef int Data;

struct Stack {
	int capacity;
	int size;
	Data * a; 
};

void stack_push(struct Stack * s, Data x)
{
	if (s->capacity >= s->size)
	{
		(s->size) *= 2;
		s->a = realloc(s->a, (s->size) * sizeof(Data));
	}
		s->a[s->capacity] = x;
		(s->capacity)++;
}

Data stack_pop(struct Stack * s)
{
	(s->capacity)--;
	Data rem = s->a[s->capacity];
	s->a[s->capacity] = 0;
	return rem;
}

Data stack_get(struct Stack * s)
{
	return s->a[s->capacity];
}

void stack_print(struct Stack * s)
{
	if (s->capacity == 0)
		printf("Empty stack\n");
	else
	{
		for (int i = 0; i < s->capacity; i++)
			printf("%d ", s->a[i]);
		printf("\n");
	}
}

int  stack_size(struct Stack * s)
{
	return s->capacity;
}

int  stack_is_empty(struct Stack * s)
{
	if (s->capacity == 0)
		return 1;
	return 0;
}

void stack_clear(struct Stack * s)
{
	for (int i = 0; i < s->capacity; i++)
		s->a[i] = 0;
	s->capacity = 0;
}

void stack_destroy(struct Stack * s)
{
	free(s->a);
	free(s);
}

struct Stack* stack_create(int size)
{
	struct Stack *s = (struct Stack *)calloc(1, sizeof(struct Stack));
	s->a = calloc(size, sizeof(Data));
	s->size = size;
	stack_clear(s);
	return s;
}

#endif