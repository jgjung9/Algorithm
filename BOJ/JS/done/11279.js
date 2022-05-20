/**
 * https://www.acmicpc.net/problem/11279
 *
 * 최대 힙 구현
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = +input[0];
const operate = input.slice(1).map(Number);

function insertMaxHeap(heap, value) {
    if (heap.length === 0) {
        heap.push(value);
        return;
    }

    heap.push(value);
    let child = heap.length - 1;
    let parent = Math.floor((child - 1) / 2);

    while (heap[child] > heap[parent] && child > 0) {
        let temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;

        child = parent;
        parent = Math.floor((child - 1) / 2);
    }
}

function deleteMaxHeap(heap) {
    if (heap.length === 0) return 0;
    if (heap.length === 1) return heap.pop();

    let temp = heap[0];
    heap[0] = heap[heap.length - 1];
    heap[heap.length - 1] = temp;
    const result = heap.pop();

    let parent = 0;
    let child;
    if (heap[1] === undefined) return result;
    if (heap[2] === undefined) child = 1;
    else child = heap[1] > heap[2] ? 1 : 2;

    while (heap[parent] < heap[child]) {
        temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;

        parent = child;
        const left = parent * 2 + 1;
        const right = parent * 2 + 2;
        if (heap[left] === undefined) break;
        if (heap[right] === undefined) child = left;
        else child = heap[left] > heap[right] ? left : right;
    }

    return result;
}

const heap = [];
const answer = [];
for (let i = 0; i < N; i++) {
    if (operate[i] === 0) {
        answer.push(deleteMaxHeap(heap));
        continue;
    }

    insertMaxHeap(heap, operate[i]);
}

console.log(answer.join('\n'));
