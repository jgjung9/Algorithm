// BOJ 2747 피보나치 수

#include <stdio.h>

int fibo(int n) {
  if (n == 0 || n == 1) return n;
  int n0 = 0, n1 = 1;
  int result;
  for (int i = 0; i < n-1; i++) {
    result = n0 + n1;
    n0 = n1;
    n1 = result;
  }
  return result;
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fibo(n));

  return 0;
}