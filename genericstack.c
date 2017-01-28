#include <stdio.h>
#include <stdlib.h>

struct node {
  void *data;
  struct node *next;
};

struct node *create_node(void *x);

void push(struct node **top, void *x);
void pop(struct node **top);
void delete_stack(struct node **top);
void print_stack(struct node *top, void (*printNode)(void*));

void printInt(void *x) { printf("%d -> ", *(int*)(x)); }
void printFloat(void *x) { printf("%0.1f -> ", *(float*)(x)); }

int main()
{
  struct node *my_stack = NULL;

  int i = 1;
  for (i = 1; i <= 10; i++) {
    int *x = (int*)malloc(sizeof(int));
    *x = i;
    push(&my_stack, x);
    print_stack(my_stack, printInt);
  }

  for (i = 0; i < 14; i++) {
    pop(&my_stack);
    print_stack(my_stack, printInt);
  }

  for (i = 1; i <= 10; i++) {
    float *y = (float*)malloc(sizeof(float));
    *y = (i / 2.0);
    push(&my_stack, y);
    print_stack(my_stack, printFloat);
  }

  printf("DELETE STACK\n");
  delete_stack(&my_stack);
  //print_stack(my_stack);

  return 0;
}


struct node *create_node(void *x)
{
  struct node *new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = x;
  new_node->next = NULL;
  return new_node;
}


void push(struct node **top, void *x)
{
  struct node *new_node = create_node(x);
  new_node->next = *top;
  *top = new_node;
  return;
}


void pop(struct node **top)
{
  if (*top != NULL) {
    struct node *tmp = *top;
    *top = (*top)->next;
    free(tmp->data);
    free(tmp);
  }
  return;
}


void delete_stack(struct node **top)
{
  while (*top != NULL)
  {
    pop(top);
  }
  return;
}


void print_stack(struct node *top, void (*printNode)(void*))
{
  struct node *r = top;
  while (r != NULL) {
    (*printNode)(r->data);
    r = r->next;
  }
  printf("NULL\n");
  return;
}
