#include <iostream>
#include <algorithm>
using namespace std;
int n, dasom, answer = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> dasom;
  int arr[n - 1];
  for (int i = 0; i < n - 1; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n - 1); 
  while (arr[n - 2] >= dasom) {
    dasom++;
    arr[n - 2]--;
    sort(arr, arr + n - 1);
    answer++;
  }
  cout << answer;
  return 0;
}