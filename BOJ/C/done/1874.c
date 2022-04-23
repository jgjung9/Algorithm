// BOJ 1874 스택수열
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef int element;
typedef struct {
  element data[MAX_SIZE];
  int top;
} StackType;

void init_stack(StackType *s){
  s->top = -1;
}

int is_empty(StackType *s){
  return s->top == -1;
}

int is_full(StackType *s){
  return s->top == (MAX_SIZE - 1);
}

void push(StackType *s, element item){
  s->data[++s->top] = item;
}

element pop(StackType *s){
  return s->data[s->top--];
}

int main(void){
  StackType s;
  init_stack(&s);
  char result[MAX_SIZE * 2];
  int result_idx = 0;
  int n, max = 0;
  int check = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    int input, output;
    scanf("%d", &input);
    while (max < input) {
      push(&s, ++max);
      result[result_idx++] = '+';
    }
    output = pop(&s);
    if (input != output) check = 1; 
    result[result_idx++] = '-';
  }

  if (check) {
    printf("NO\n");
    return 0;
  }

  for (int i = 0; i < result_idx; i++){
    printf("%c\n", result[i]);
  }

  return 0;
}