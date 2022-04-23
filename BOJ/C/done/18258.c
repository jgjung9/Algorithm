// BOJ 18258 큐 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_SIZE 10

typedef int element;
typedef struct {
  element* data;
  int front;
  int rear;
} queue;

int empty(queue *q){
  return q->front == q->rear;
}

void push(queue *q, element item){
  q->data[++q->rear] = item;
}

element pop(queue *q){
  if (empty(q)) return -1;
  return q->data[++q->front];
}

int size(queue *q){
  return q->rear - q->front;
}

int main(void){
  queue q;
  int n;
  scanf("%d", &n);
  q.front = -1;
  q.rear = -1;

  q.data = calloc(n, sizeof(element));

  for (int i = 0; i < n; i++) {
    char command[MAX_COMMAND_SIZE];
    scanf("%s", command);
    if (!strcmp(command, "push")) {
      int x;
      scanf("%d", &x);
      push(&q, x);
    } 
    else if (!strcmp(command, "pop")) printf("%d\n", pop(&q));
    else if (!strcmp(command, "size")) printf("%d\n", size(&q));
    else if (!strcmp(command, "empty")) printf("%d\n", empty(&q));
    else if (!strcmp(command, "front")) {
      if (q.front == q.rear) printf("-1\n");
      else printf("%d\n",q.data[q.front+1]);
    }
    else if (!strcmp(command, "back")) {
      if (q.front == q.rear) printf("-1\n");
      else printf("%d\n", q.data[q.rear]);
    }
  }
  free(q.data);
  return 0;
}
