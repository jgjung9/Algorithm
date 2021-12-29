// BOJ 2750 수 정렬하기
#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, z) ((z)=(x), (x)=(y), (y)=(z))

void selection_sort(int list[], int n) {
  int i, j, least, temp;
  for (i = 0; i < n-1; i++) {
    least = i;
    for (j = i + 1; j < n; j++) {
      if (list[least] > list[j]) least = j;
    }
    SWAP(list[i], list[least], temp);
  }
}

int main() {
  int n, i;
  scanf("%d", &n);

  int list[n];
  for (i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    list[i] = x;
  }

  selection_sort(list, n);

  for (i = 0; i < n; i++) {
    printf("%d\n", list[i]);
  }
  return 0;
}