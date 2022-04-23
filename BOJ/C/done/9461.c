// BOJ 9461 파도반 수열
#include <stdio.h>
#define MAX 101

int main() {
  int t;
  long p[MAX];
  scanf("%d", &t);
 
  p[1] = 1;
  p[2] = 1;
  p[3] = 1;
  p[4] = 2;
  p[5] = 2;
  for (int i = 6; i < MAX; i++) {
    p[i] = p[i-1] + p[i-5];
  }

  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    printf("%ld\n", p[n]);
  }

  return 0;
}