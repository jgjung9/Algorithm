// BOJ 4153 직각삼각형
#include <stdio.h>

int main() {
  while (1) {
    int a, b, c;
    long a2, b2, c2;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0 && b == 0 && c == 0) break;
    a2 = a * a;
    b2 = b * b;
    c2 = c * c;
    if ((a2+b2) == c2 ||
        (a2+c2) == b2 ||
        (b2+c2) == a2) printf("right\n");
    else printf("wrong\n");
  }

  return 0;
}