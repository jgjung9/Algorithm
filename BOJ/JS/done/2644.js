/**
 * https://www.acmicpc.net/problem/2644
 *
 * BFS를 활용한 촌수 계산 문제
 */
const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const n = +input[0];
const [start, target] = input[1].split(' ').map(Number);
const edges = input.slice(3);
const graph = [];
for (let i = 0; i < n; i++) {
  const row = [];
  graph.push(row);
}

edges.forEach((edge) => {
  const [v, u] = edge.split(' ').map(Number);
  graph[v - 1].push(u - 1);
  graph[u - 1].push(v - 1);
});

const visited = Array(n).fill(0);
const found = Array(n).fill(false);
const queue = [];
let front = 0;
let rear = 0;
function BFS(vertex, depth) {
  visited[vertex] = depth;
  for (let i = 0; i < graph[vertex].length; i++) {
    const next = graph[vertex][i];
    if (visited[next]) continue;
    if (found[next]) continue;
    queue.push([next, depth + 1]);
    rear++;
  }
}

BFS(start - 1, 1);

while (front != rear) {
  const [next, depth] = queue[front++];
  BFS(next, depth);
}

console.log(visited[target - 1] - 1);
