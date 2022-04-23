// BOJ 1874 스택수열
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
  element *data;
  int top;
} StackType;

void init_stack(StackType *s){
  s->top = -1;
}

void push(StackType *s, element item){
  s->data[++s->top] = item;
}

element pop(StackType *s){
  return s->data[s->top--];
}

int main(void){
  int n, max = 0;
  scanf("%d", &n);
  char *result = calloc(n*2, sizeof(char));
  int result_idx = 0;
  int check = 0;

  StackType s;
  init_stack(&s);
  s.data = calloc(n, sizeof(element));

  for (int i = 0; i < n; i++){
    int input, output;
    scanf("%d", &input);
    while (max < input) {
      push(&s, ++max);
      result[result_idx++] = '+';
    }
    output = pop(&s);
    if (output != input) {
      check = 1;
    }
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