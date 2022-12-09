#include <iostream>
using namespace std;
int n, k, cnt = 0;

void merge(int arr[], int p, int q, int r) {
  int temp[r - p + 1];
  int i = p, j = q + 1, t = 0; 
  while (i <= q && j <= r) {
    if (arr[i] <= arr[j])
      temp[t++] = arr[i++];
    else 
      temp[t++] = arr[j++];
  }

  while (i <= q) 
    temp[t++] = arr[i++];
  while (j <= r) 
    temp[t++] = arr[j++];

  i = p, t = 0;
  while (i <= r) {
    arr[i++] = temp[t++]; 
    cnt++;
    if (cnt == k) {
      cout << arr[i - 1];
      return;
    }
  }
}

void mergeSort(int arr[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> k;
  int arr[500000];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  mergeSort(arr, 0, n - 1);
  if (cnt < k)
   cout << -1;
  return 0;
}