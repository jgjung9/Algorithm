// BOJ 2748 피보나치 수 2
#include <stdio.h>

long fibo(int n) {
  if ((n == 0) || (n == 1)) return n;
  else {
    long n1 = 0, n2 = 1; 
    long result;                 
    for (int i = 0; i < n-1; i++) {
      result = n1 + n2;
      n1 = n2;
      n2 = result;
    }
    return result;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%ld\n", fibo(n));

  return 0;  
}