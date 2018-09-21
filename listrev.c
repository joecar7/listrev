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

static void reverse(struct node **list)
{
	struct node *prev = NULL;
	struct node *next;
	struct node *curr = *list;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*list = prev;
}

int main(int argc, char **argv)
{
	struct node *list = NULL;
	uint i;

	for (i = 0; i < 10; i++)
		make(&list, i);
	say_list(list);
	reverse(&list);
	say_list(list);

	return 0;
}
