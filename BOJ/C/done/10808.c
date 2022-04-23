// BOJ  10808 알파벳 개수

#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
  int alphabet[26] = {0};
  char ch;
  char s[MAX];
  scanf("%s", s);
  for (int i = 0; i < strlen(s); i++) {
    ch = s[i] - 'a';
    alphabet[ch]++;
  }
  for (int i = 0; i < 26; i++) printf("%d ", alphabet[i]);
  printf("\n");
  return 0;
}