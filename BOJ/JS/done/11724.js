/**
 * https://www.acmicpc.net/problem/11724
 *
 * hint: DFS or BFS를 이용해 서치하여 Connected Compnent의 개수를 구한다.
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const [N, M] = input[0].split(' ').map(Number);
const edges = input.slice(1);

const graph = [];
const visited = Array(N).fill(false);
for (let i = 0; i < N; i++) {
    graph.push([]);
}

edges.forEach((edge) => {
    const [u, v] = edge.split(' ').map(Number);
    graph[u - 1].push(v - 1);
    graph[v - 1].push(u - 1);
});

let count = 0;
function Dfs(vetex) {
    if (visited[vetex]) return;
    visited[vetex] = true;
    count++;

    for (let i = 0; i < graph[vetex].length; i++) {
        Dfs(graph[vetex][i]);
    }
}

let answer = 0;
let pre = count;
for (let i = 0; i < N; i++) {
    Dfs(i);
    if (pre !== count) {
        pre = count;
        answer++;
    }
}

console.log(answer);
