const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const n = +input[0];
const operator = input.slice(1).map(Number);
const heap = [];

function insertHeap(n) {
  let now = heap.length;
  let parent = Math.floor((now - 1) / 2);
  heap.push(n);
  while (Math.abs(heap[parent]) >= Math.abs(heap[now]) && now > 0) {
    if (
      Math.abs(heap[parent]) === Math.abs(heap[now]) &&
      heap[parent] < heap[now]
    ) {
      break;
    }

    let temp = heap[now];
    heap[now] = heap[parent];
    heap[parent] = temp;
    now = parent;
    parent = Math.floor((now - 1) / 2);
  }
}

function deleteHeap() {
  if (heap.length === 0) return 0;
  let ans = heap[0];
  heap[0] = heap[heap.length - 1];
  heap.pop();

  let parent = 0;

  let child = heap[1] && 1;
  if (heap[2]) {
    if (Math.abs(heap[1]) === Math.abs(heap[2]))
      child = heap[1] < heap[2] ? 1 : 2;
    else if (Math.abs(heap[1]) > Math.abs(heap[2])) child = 2;
  }

  while (Math.abs(heap[parent]) >= Math.abs(heap[child])) {
    if (
      Math.abs(heap[parent]) === Math.abs(heap[child]) &&
      heap[parent] < heap[child]
    ) {
      break;
    }

    let temp = heap[parent];
    heap[parent] = heap[child];
    heap[child] = temp;
    parent = child;
    let left = parent * 2 + 1;
    let right = parent * 2 + 2;

    child = heap[left] && left;
    if (heap[right]) {
      if (Math.abs(heap[left]) === Math.abs(heap[right]))
        child = heap[left] < heap[right] ? left : right;
      else if (Math.abs(heap[left]) > Math.abs(heap[right])) child = right;
    }

    if (!child) break;
  }
  return ans;
}

const ans = [];
operator.forEach((v) => {
  if (v === 0) {
    ans.push(deleteHeap());
  } else {
    insertHeap(v);
  }
});
console.log(ans.join('\n'));
