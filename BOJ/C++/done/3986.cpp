#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n, answer = 0;
string str;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;

  while (n--) {
    cin >> str;
    if (str.size() % 2 != 0)
      continue;
      
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
      if (s.empty() || s.top() != str[i])
        s.push(str[i]);
      else
        s.pop();
    }
    if (s.empty())
      answer++;
  }
  cout << answer;
  return 0;
}