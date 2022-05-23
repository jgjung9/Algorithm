/**
 * https://www.acmicpc.net/problem/1260
 *
 * hint: DFS BFS 구현
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [N, M, V] = input[0].split(' ').map(Number);
const edges = input.slice(1);

const graph = [];
const dfsVisited = Array(N).fill(false);
const bfsVisited = Array(N).fill(false);
const found = Array(N).fill(false);
const queue = [];
let front = 0;
let rear = 0;

const dfsAnswer = [];
const bfsAnswer = [];

for (let i = 0; i < N; i++) {
    graph.push(Array(N).fill(0));
}

edges.forEach((edge) => {
    const [x, y] = edge.split(' ').map(Number);
    graph[x - 1][y - 1] = 1;
    graph[y - 1][x - 1] = 1;
});

function Dfs(vetex) {
    if (dfsVisited[vetex]) return;
    dfsVisited[vetex] = true;
    dfsAnswer.push(vetex + 1);

    for (let i = 0; i < N; i++) {
        if (dfsVisited[i]) continue;
        if (graph[vetex][i] === 1) Dfs(i);
    }
}

function Bfs(vetex) {
    if (bfsVisited[vetex]) return;
    bfsVisited[vetex] = true;
    bfsAnswer.push(vetex + 1);

    for (let i = 0; i < N; i++) {
        if (bfsVisited[i]) continue;
        if (found[i]) continue;
        if (graph[vetex][i] === 1) {
            queue.push(i);
            found[i] = true;
            rear++;
        }
    }
}

Dfs(V - 1);
Bfs(V - 1);

while (front !== rear) {
    Bfs(queue[front++]);
}

console.log(dfsAnswer.join(' '));
console.log(bfsAnswer.join(' '));
