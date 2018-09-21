#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	uint val;
};

static struct node *make(struct node **list, uint val)
{
	struct node *node = malloc(sizeof(*node));

	if (node) {
		node->next = *list;
		node->val = val;
		*list = node;
	}

	return node;
}

static void say_node(struct node *node)
{
	printf("%p(%u,%p)\n", node, node->val, node->next);
}

static void say_list(struct node *list)
{
	if (!list) {
		printf("\n");
	} else {
		say_node(list);
		say_list(list->next);
	}
}

static struct node *reverse(struct node *list)
{
	if (!list->next)
		return list;

	struct node *tail = reverse(list->next);
	list->next->next = list;
	list->next = NULL;

	return tail;
}

int main(int argc, char **argv)
{
	struct node *list = NULL;
	uint i;

	for (i = 0; i < 10; i++)
		make(&list, i);
	say_list(list);
	if (list)
		list = reverse(list);
	say_list(list);

	return 0;
}
