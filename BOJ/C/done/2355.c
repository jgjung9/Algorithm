// BOJ 2355 시그마

#include <stdio.h>

int main() {
  long a, b; 
  long long result = 0;
  scanf("%ld %ld", &a, &b);
  if (a <= b ) result = ((a + b) * (b - a + 1) / 2);
  else result = ((a + b) * (a - b + 1) / 2);  
  printf("%lld\n", result);

  return 0;
}