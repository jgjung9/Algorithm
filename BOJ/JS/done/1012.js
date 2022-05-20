/**
 * https://www.acmicpc.net/problem/1012
 *
 * hint: DFS 또는 BFS를 활용해 모든 점을 탐색한다
 * 모든점에 대해 DFS or BFS를 진행하고 진행 전과 진행 후 visited가 변할 경우
 * answer++ 해준다.
 */

const fs = require('fs');
let input = fs.readFileSync('./input.txt').toString().trim().split('\n');
const T = +input.shift();

// left 0 down 1 right 2 up 3 / 세로축 X 가로축 Y
const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];

let count = 0;
function Dfs(x, y, graph, visited) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    count++;

    for (let dir = 0; dir < 4; dir++) {
        const posX = x + dx[dir];
        const posY = y + dy[dir];
        if (posX < 0 || posX >= graph.length) continue;
        if (posY < 0 || posY >= graph[0].length) continue;
        if (graph[posX][posY] === 0) continue;

        Dfs(posX, posY, graph, visited);
    }
}

for (let i = 0; i < T; i++) {
    const [M, N, K] = input[0].split(' ').map(Number);
    const locations = input.slice(1, K + 1);
    input = input.slice(K + 1);

    const graph = Array(M);
    const visited = Array(M);
    for (let i = 0; i < M; i++) {
        graph[i] = Array(N).fill(0);
        visited[i] = Array(N).fill(false);
    }
    for (let loc of locations) {
        const [x, y] = loc.split(' ').map(Number);
        graph[x][y] = 1;
    }

    let answer = 0;
    let result = count;
    for (let i = 0; i < M; i++) {
        for (let j = 0; j < N; j++) {
            if (graph[i][j] !== 0) {
                Dfs(i, j, graph, visited);
            }
            if (result !== count) {
                result = count;
                answer++;
            }
        }
    }
    console.log(answer);
}
