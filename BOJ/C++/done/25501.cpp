#include <iostream>
#include <string>
using namespace std;

void isPalindrome(string str) {
  int l = 0, r = str.size() - 1, cnt = 0, answer = 1;
  while (l < r) {
    cnt++;
    if (str[l] != str[r]) {
      answer = 0;
      break;
    }
    l++, r--;
  }
  if (answer == 1) 
    cnt++;
  cout << answer << ' ' << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;  
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    isPalindrome(s);
  }
  return 0;
}