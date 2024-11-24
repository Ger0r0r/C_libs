#ifndef DOUBLE_LINKED_LIST_LIBRARY
#define DOUBLE_LINKED_LIST_LIBRARY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataDLL;

struct Node {
	struct Node * next;
	struct Node * prev;
	DataDLL data;
};

const DataDLL BarrierElement = 0xDEADFA11;

void list_init(struct Node * list)
{
	list->data = BarrierElement;
	list->next = list;
	list->prev = list;
}

void list_insert(struct Node * list, struct Node * t)
{
	struct Node * tist;
	tist = list->next;
	tist->prev = t;
	list->next = t;
	t->next = tist;
	t->prev = list;
}

void list_insert_before(struct Node * list, struct Node * t)
{
	struct Node * tist;
	tist = list->prev;
	tist->next = t;
	list->prev = t;
	t->prev = tist;
	t->next = list;
}

void list_remove(struct Node * t)
{
	
	struct Node * list = t->next;
	struct Node * tist = t->prev;
	list->prev = tist;
	tist->next = list;
	t->next = t;
	t->prev = t;
}

DataDLL list_delete(struct Node * t)
{
	DataDLL tt = t->data;
	list_remove(t);
	free(t);
	return tt;
}

struct Node * list_push_front(struct Node * list, DataDLL d)
{
	struct Node * t = malloc(sizeof(struct Node));
	if (t == NULL)
		return t;
	t->data = d;
	list_insert(list, t);
	return t;
	
}

struct Node * list_push_back(struct Node * list, DataDLL d)
{
	struct Node * t = malloc(sizeof(struct Node));
	if (t == NULL)
		return t;
	t->data = d;
	list_insert_before(list, t);
	return t;
}

DataDLL list_pop_front(struct Node * list)
{
	return list_delete(list->next);
}

DataDLL list_pop_back(struct Node * list)
{
	return list_delete(list->prev);
}

void list_print (struct Node * list)
{
	struct Node * t = list;
	while (t->next->data != BarrierElement)
	{
		printf("%i ", t->next->data);
		t = t->next;
	}
	printf("\n");
}

int list_is_empty(struct Node * list)
{
	if (list->next->data == BarrierElement)
		return 1;
	return 0;
}

void list_clear(struct Node * list)
{
	struct Node * t = list;
	while(!list_is_empty(list))
	{
		t = list->next;
		list_remove(list->next);
		free(t);
	}
}

#endif