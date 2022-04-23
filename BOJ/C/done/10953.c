// BOJ 10953 A+B -6
#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    int a, b;;
    scanf("%d,%d", &a, &b);
    printf("%d\n", a+b);
  }
  return 0;
}