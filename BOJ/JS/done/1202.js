const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [n, k] = input[0].split(' ').map(Number);
const jewelries = input
  .slice(1, n + 1)
  .map((item) => {
    return item.split(' ').map(Number);
  })
  .sort((a, b) => {
    const m1 = a[0];
    const m2 = b[0];
    if (m1 > m2) return -1;
    else return 1;
  });
const bags = input
  .slice(n + 1)
  .map(Number)
  .sort((a, b) => a - b);

function swap(arr, a, b) {
  const temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

const heap = [];
function insertHeap(n) {
  heap.push(n);
  let now = heap.length - 1;
  let parent = Math.floor((now - 1) / 2);
  while (heap[parent] < heap[now]) {
    swap(heap, parent, now);
    now = parent;
    parent = Math.floor((now - 1) / 2);
  }
}

function deleteHeap() {
  if (heap.length === 0) return 0;
  if (heap.length === 1) return heap.pop();

  const ans = heap[0];
  heap[0] = heap[heap.length - 1];
  heap.pop();

  let parent = 0;
  let child;
  if (heap[1] && !heap[2]) child = 1;
  else child = heap[1] > heap[2] ? 1 : 2;

  while (heap[parent] < heap[child]) {
    swap(heap, parent, child);
    parent = child;
    const left = parent * 2 + 1;
    const right = parent * 2 + 2;
    if (!heap[left] && !heap[right]) break;
    else if (heap[left] && !heap[right]) child = left;
    else child = heap[left] > heap[right] ? left : right;
  }
  return ans;
}

let ans = 0;
for (let i = 0; i < k; i++) {
  const c = bags[i];
  if (jewelries.length === 0 && heap.length === 0) break;

  while (true) {
    if (jewelries.length === 0) {
      ans += deleteHeap();
      break;
    }
    const [m, v] = jewelries[jewelries.length - 1];
    if (m <= c) {
      insertHeap(v);
      jewelries.pop();
    } else {
      ans += deleteHeap();
      break;
    }
  }
}

console.log(ans);
