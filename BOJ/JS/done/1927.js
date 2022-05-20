/**
 * https://www.acmicpc.net/problem/1927
 *
 * 최소 힙 트리 구현
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const N = +input[0];
const operate = input.slice(1).map(Number);

function insertMinHeap(heap, value) {
    if (heap.length === 0) {
        heap.push(value);
        return;
    }

    heap.push(value);
    let parent = Math.floor((heap.length - 2) / 2);
    let child = heap.length - 1;
    while (heap[parent] > heap[child]) {
        let temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        if (child === 0) break;
        parent = Math.floor((child - 1) / 2);
    }
}

function deleteMinHeap(heap) {
    if (heap.length === 0) return 0;
    if (heap.length === 1) return heap.pop();

    let temp = heap[0];
    heap[0] = heap[heap.length - 1];
    heap[heap.length - 1] = temp;
    const result = heap.pop();

    let parent = 0;
    let child;
    if (heap[2] === undefined) child = 1;
    else child = heap[1] < heap[2] ? 1 : 2;

    while (heap[parent] > heap[child]) {
        temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        parent = child;

        if (heap[parent * 2 + 1] === undefined) break;
        if (heap[parent * 2 + 2] === undefined) child = parent * 2 + 1;
        else {
            child =
                heap[parent * 2 + 1] < heap[parent * 2 + 2]
                    ? parent * 2 + 1
                    : parent * 2 + 2;
        }
    }

    return result;
}

const heap = [];
const answer = [];
for (let i = 0; i < N; i++) {
    if (operate[i] === 0) {
        answer.push(deleteMinHeap(heap));
        continue;
    }
    insertMinHeap(heap, operate[i]);
}

console.log(answer.join('\n'));
