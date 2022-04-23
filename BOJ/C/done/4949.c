// BOJ 4949 균형잡힌 세상
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef char element;
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

int check_valance(char *str){
  StackType s;
  init_stack(&s);
  char ch, open_ch;
  int n = strlen(str);
  for (int i = 0; i < n; i++){
    ch = str[i];
    switch(ch){
      case '(': case '[':
        push(&s, ch);
        break;
      case ')': case ']':
        if (is_empty(&s)) return 0;
        open_ch = pop(&s);
        if ((ch == ')' && open_ch != '(')||
            (ch == ']' && open_ch != '[')) 
            return 0;
        break;
    }
  }
  if (!is_empty(&s)) return 0;
  return 1;
}

int main(void){
  while (1) {
    char str[MAX_SIZE];
    gets(str);

    if (!strcmp(str, ".")) break;

    if (check_valance(str)) printf("yes\n");
    else printf("no\n"); 
  }
  
  return 0;
}