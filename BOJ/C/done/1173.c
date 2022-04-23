//  BOJ 1173 운동

#include <stdio.h>

int main() {
  int N, m, M, T, R;
  scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);
  int time = 0, exer_time = 0, pulse = m;

  if (m + T > M) time = -1;
  else {
    while (exer_time != N) {
      if (pulse + T <= M) {
        pulse += T;
        exer_time++;
        time++;
      }
      else {
        pulse -= R;
        if (pulse < m) pulse = m;
        time++;
      }
    }
  }
  printf("%d\n", time);
  return 0;
}