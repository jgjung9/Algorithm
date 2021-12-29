// BOJ 10845 큐
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10001
#define MAX_COMMAND_SIZE 10

typedef int element;
typedef struct {
  element data[MAX_QUEUE_SIZE];
  int front, rear;
} queue;

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

int empty(queue *q){
  return q->front == q->rear;
}

void print_front(queue *q){
  if (empty(q)) printf("-1\n");
  else printf("%d\n", q->data[q->front + 1]);
}

void print_back(queue *q){
  if (empty(q)) printf("-1\n");
  else printf("%d\n", q->data[q->rear]);
}

int main(){
  int n;
  queue q;
  q.front = 0;
  q.rear = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++){
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
    else if (!strcmp(command, "front")) print_front(&q);
    else if (!strcmp(command, "back")) print_back(&q);
  }

  return 0;
}