/**
 * https://www.acmicpc.net/problem/24479
 */
const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');

const [n, m, r] = input[0].split(' ').map(Number);
const edges = input.slice(1);

const visited = Array(n).fill(0);
const graph = [];
for (let i = 0; i < n; i++) {
    graph.push([]);
}
edges.forEach((edge) => {
    const [v, u] = edge.split(' ').map(Number);
    graph[v - 1].push(u - 1);
    graph[u - 1].push(v - 1);
});

graph.forEach((row) => {
    row.sort((a, b) => a - b);
});

let count = 1;
function DFS(vertex) {
    if (visited[vertex] != 0) return;
    visited[vertex] = count;
    count++;
    graph[vertex].forEach((next) => {
        DFS(next);
    });
}

DFS(r - 1);
console.log(visited.join('\n'));
