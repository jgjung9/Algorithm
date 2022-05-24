/**
 * https://www.acmicpc.net/problem/4963
 *
 * hint: BFS or DFS를 이용해 섬들을 탐색해 총 섬의 개수를 찾는다
 */

const fs = require('fs');
let input = fs.readFileSync('./input.txt').toString().trim().split('\n');

// 세로축 y, 가로축 x , left down right up leftup leftdown rightdown rightup
const dy = [0, 1, 0, -1, -1, 1, 1, -1];
const dx = [-1, 0, 1, 0, -1, -1, 1, 1];
function DFS(y, x, graph, visited, w, h) {
    if (visited[y][x]) return;
    visited[y][x] = true;

    for (let dir = 0; dir < 8; dir++) {
        const nextY = y + dy[dir];
        const nextX = x + dx[dir];
        if (nextX < 0 || nextX >= w) continue;
        if (nextY < 0 || nextY >= h) continue;
        if (graph[nextY][nextX] === 0) continue;
        DFS(nextY, nextX, graph, visited, w, h);
    }
}

function visitedCount(visited, w, h) {
    let count = 0;
    for (let i = 0; i < h; i++) {
        for (let j = 0; j < w; j++) {
            if (visited[i][j]) count++;
        }
    }
    return count;
}

while (input[0] !== '0 0') {
    const [w, h] = input[0].split(' ').map(Number);
    const graph = [];
    for (let i = 1; i < h + 1; i++) {
        graph.push(input[i].split(' ').map(Number));
    }
    const visited = [];
    for (let i = 0; i < h; i++) {
        visited.push(Array(w).fill(false));
    }

    let count = 0;
    let searchCount = 0;
    for (let y = 0; y < h; y++) {
        for (let x = 0; x < w; x++) {
            if (graph[y][x] !== 0) DFS(y, x, graph, visited, w, h);
            const visitedCnt = visitedCount(visited, w, h);
            if (searchCount !== visitedCnt) {
                searchCount = visitedCnt;
                count++;
            }
        }
    }
    input = input.slice(h + 1);
    console.log(count);
}
