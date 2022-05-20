/**
 * https://www.acmicpc.net/problem/2606
 *
 * hint: 간단한 그래프 탐색 문제로 bfs or dfs로 점들을 탐색하고
 * 자신을 제외한 탐색한 정점의 개수를 반환
 */

const fs = require('fs');
const input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const vetexCnt = +input.shift();
const edgeCnt = +input.shift();
const edges = input;

const graph = [];
const visited = Array(vetexCnt).fill(false);
for (let i = 0; i < vetexCnt; i++) {
    graph.push(Array(vetexCnt).fill(0));
}

edges.forEach((edge) => {
    edge = edge.split(' ').map(Number);
    graph[edge[0] - 1][edge[1] - 1] = 1;
    graph[edge[1] - 1][edge[0] - 1] = 1;
});

let count = 0;
function dfs(vetex) {
    if (visited[vetex]) {
        return;
    } else {
        visited[vetex] = true;
        count++;
    }

    for (let i = 0; i < vetexCnt; i++) {
        if (graph[vetex][i] === 1) dfs(i);
    }
}

dfs(0);
console.log(count - 1);
